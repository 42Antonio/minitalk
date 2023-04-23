#include	"include/minitalk_bonus.h"
void	ft_unbit(int signal, siginfo_t	*pid, void *context)
{
	static	int	bit;
	static	int	i;

	(void)context;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << (7 - bit));
		// int j;
  		// for (j = 0; j < 8; j++) {
    	// printf("%d", !!((i << j) & 0x80)); }
  		// printf("\n");
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c",i);
		if (i == 0)
			kill (pid -> si_pid, SIGUSR2);
		bit = 0;
		i = 0;
	}	
}

int	main(int ac, char	**av)
{
	int pid;
	struct sigaction	siga;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	siga.sa_sigaction = ft_unbit;
	//sigemptyset(&siga.sa_mask);
	//siga.sa_flags = 0;

	while(1)
	{	
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);	
		pause();
	}
	return (0);
}
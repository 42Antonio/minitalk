#include	"include/minitalk_bonus.h"

void	ft_unbit(int signal, siginfo_t	*pid, void *context)
{
	static int	bit;
	static int	i;
	static int	flag;

	(void)context;
	if (signal == SIGUSR1)
	{
		flag = 1;
		i |= (0x01 << (7 - bit));
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (i == 0 && flag == 1)
			kill (pid -> si_pid, SIGUSR2);
		bit = 0;
		i = 0;
	}	
}

int	main(int ac, char	**av)
{
	int					pid;
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
	sigemptyset(&siga.sa_mask);
	siga.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
		pause();
	}
	return (0);
}

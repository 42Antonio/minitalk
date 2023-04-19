#include	"include/minitalk.h"
void	ft_unbit(int signal)
{
	static	int	bit;
	static	int	i;

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
		bit = 0;
		i = 0;
	}	
}

int	main(int ac, char	**av)
{
	int pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while(1)
	{	
		signal(SIGUSR1, ft_unbit);
		signal(SIGUSR2, ft_unbit);	
		pause();
	}
	return (0);
}
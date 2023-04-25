#include	"include/minitalk.h"

void	ft_unbit(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}	
}

int	main(int ac, char	**av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{	
		signal(SIGUSR1, ft_unbit);
		signal(SIGUSR2, ft_unbit);
		pause();
	}
	return (0);
}

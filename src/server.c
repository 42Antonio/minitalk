#include	"../include/minitalk.h"

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
}
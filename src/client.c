#include	"../include/minitalk.h"



int	main(int ac, char	**av)
{
	int pid;
	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	else
	{
		pid = ft_atoi(av[1]);
		printf("\n El pid es: %i", pid);
	}
}
#include	"include/minitalk.h"

static void	client_str(int	pid, char	*str)
{
	int		bit;
	char	c;
	int		i;

	i = 0;
	while(str[i])
	{
		bit = 8;
		c = str[i];
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}
int	main(int ac, char	**av)
{
	if (ac == 3)
	{
		client_str(ft_atoi(av[1]), av[2]);
		return (0);
	}
	else
		return (1);
}
#include	"include/minitalk_bonus.h"

static void	received(int	signal)
{
	
	if (signal == SIGUSR2)
	{
		printf("\nMessage received");
		exit(0);
	}
}

static void	client_str(int	pid, char	c)
{
	int		bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}
int	main(int ac, char	**av)
{
	int i;

	i = 0;
	if (ac == 3)
	{	
		while(av[2][i] != '\0'){
			client_str(ft_atoi(av[1]), av[2][i]);
			i++;
		}
		signal(SIGUSR2, received);
		client_str(ft_atoi(av[1]), '\0');
		return (0);
	}
	else
		return (1);
}
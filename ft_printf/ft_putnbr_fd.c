/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclaros- <aclaros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:21:36 by aclaros-          #+#    #+#             */
/*   Updated: 2022/11/15 13:43:59 by aclaros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(char a, long int n, int fd, int count)
{
	if (a == 'u')
	{
		if (n < 0)
			return (ft_putnbr_fd('o', 4294967295 + n + 1, fd, count));
		return (ft_putnbr_fd('o', n, fd, count));
	}
	if (n < 0)
	{
		count++;
		ft_putchar_fd('-', fd);
		count = ft_putnbr_fd('o', -n, fd, count);
	}
	else if (n >= 10)
	{
		count++;
		count = ft_putnbr_fd('o', n / 10, fd, count);
		ft_putnbr_fd('o', n % 10, fd, count);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}

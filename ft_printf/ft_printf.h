/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclaros- <aclaros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:30 by aclaros-          #+#    #+#             */
/*   Updated: 2022/11/15 13:02:55 by aclaros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(char a, long int n, int fd, int count);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstr_fp(char *s, int count);
int		ft_printf(char const *a, ...);
int		ft_putnbr_base(char a, unsigned int nbr, int count);

#endif

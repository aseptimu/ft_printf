/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:12:51 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/08 21:49:53 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_uint(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_uint(n / 10, fd);
		ft_putnbr_uint(n % 10, fd);
	}
}

void	print_flag_int(t_params *par, int *tmp)
{
	if (par->neg == 1)
	{
		ft_putchar_fd('-', 1);
		par->neg = 0;
	}
	if (par->plus == 1)
	{
		ft_putchar_fd('+', 1);
		(*tmp)++;
		par->plus = 0;
	}
	if (par->space == 1)
	{
		ft_putchar_fd(' ', 1);
		(*tmp)++;
		par->space = 0;
	}
}

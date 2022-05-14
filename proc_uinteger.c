/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_uinteger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/05 17:12:42 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putunsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putunsigned_fd(n / 10, fd);
		ft_putunsigned_fd(n % 10, fd);
	}
}

static int	proc_int_minus(t_params params, unsigned int tmp, \
							unsigned int i, unsigned int length)
{
	tmp += proc_precision(params.precision, length);
	ft_putunsigned_fd(i, 1);
	tmp += proc_width(params.width, params.zero, tmp);
	return (tmp);
}

static int	proc_int_no_minus(t_params params, unsigned int tmp, \
								unsigned int i, unsigned int length)
{
	if ((long)params.precision >= (long)tmp)
		tmp += proc_width(params.width, params.zero, \
		params.space + params.plus + params.precision);
	else
		tmp += proc_width(params.width, params.zero, \
		tmp + params.space + params.plus);
	tmp += proc_precision(params.precision, length);
	ft_putunsigned_fd(i, 1);
	return (tmp);
}

int	proc_uinteger(t_params params, unsigned int i)
{
	int				length;
	unsigned int	tmp;

	length = 0;
	tmp = i;
	if (i == 0)
		length++;
	while (tmp)
	{
		tmp /= 10;
		length++;
	}
	if (params.precision == 0 && i == 0)
	{
		tmp = proc_width(params.width, params.zero, 0);
		return (tmp);
	}
	tmp = length;
	if (params.minus == 1)
		tmp = proc_int_minus(params, tmp, i, length);
	if (params.minus == 0)
		tmp = proc_int_no_minus(params, tmp, i, length);
	return (tmp);
}

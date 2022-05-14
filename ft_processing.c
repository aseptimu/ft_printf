/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/08 21:48:36 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	proc_width(int width, int zero, int length)
{
	char	c;
	int		count;

	c = ' ';
	count = 0;
	if (zero == 1)
		c = '0';
	while (width > length)
	{
		ft_putchar_fd(c, 1);
		width--;
		count++;
	}
	return (count);
}

int	proc_precision(int precision, int length)
{
	int	count;

	count = 0;
	while (precision > length)
	{
		ft_putchar_fd('0', 1);
		precision--;
		count++;
	}
	return (count);
}

int	proc_char(t_params params, char c)
{
	int	index;

	if (params.minus == 1)
		ft_putchar_fd(c, 1);
	index = proc_width(params.width, params.zero, 1);
	if (params.minus == 0)
		ft_putchar_fd(c, 1);
	return (++index);
}

int	proc_percent(t_params params, char c)
{
	int	length;

	length = 1;
	if (params.zero1 == 1)
		params.zero = 1;
	if (params.minus == 0)
		length += proc_width(params.width, params.zero, length);
	ft_putchar_fd(c, 1);
	if (params.minus == 1)
		length += proc_width(params.width, params.zero, length);
	return (length);
}

int	ft_processing(t_params params, va_list ap)
{
	int	length;

	length = 0;
	if (params.type == 'c')
		length += proc_char(params, va_arg(ap, int));
	if (params.type == 's')
		length += proc_string(params, va_arg(ap, char *));
	if (params.type == 'p')
		length += proc_pointer(params, va_arg(ap, void *));
	if (params.type == 'd' || params.type == 'i')
		length += proc_integer(params, va_arg(ap, int));
	if (params.type == 'u')
		length += proc_uinteger(params, va_arg(ap, unsigned int));
	if (params.type == 'x')
		length += proc_hexadecimal(params, va_arg(ap, unsigned int));
	if (params.type == 'X')
		length += proc_hexadecimal(params, va_arg(ap, unsigned int));
	if (params.type == '%')
		length += proc_percent(params, '%');
	return (length);
}

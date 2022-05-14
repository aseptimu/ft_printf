/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/08 14:38:59 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_params	new_params_list(void)
{
	t_params	pa;

	pa.minus = 0;
	pa.plus = 0;
	pa.space = 0;
	pa.hash = 0;
	pa.zero = 0;
	pa.width = 0;
	pa.precision = -1;
	pa.asterisk = 0;
	pa.type = 0;
	pa.neg = 0;
	pa.zero1 = 0;
	return (pa);
}

static int	ft_parse(char *format, va_list ap)
{
	int			index;
	int			length;
	t_params	params;

	index = 0;
	length = 0;
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			params = new_params_list();
			index = ft_check_arg_params(format, &params, ap, index);
			length += ft_processing(params, ap);
		}
		else
		{
			ft_putchar_fd(format[index++], 1);
			length++;
		}
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	va_start(ap, format);
	length = ft_parse((char *)format, ap);
	va_end(ap);
	return (length);
}

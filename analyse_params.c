/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/08 20:59:50 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	check_flags(const char *format, t_params *params, int index)
{
	if (format[index] == '0' && params->precision == -1 && !params->minus)
		params->zero = 1;
	if (format[index] == '-')
	{
		params->minus = 1;
		params->zero = 0;
	}
	if (format[index] == '+')
	{
		params->plus = 1;
		params->space = 0;
	}
	if (format[index] == '#')
		params->hash = 2;
	if (format[index] == ' ' && params->plus == 0)
		params->space = 1;
}

static void	check_width(char *format, int *index, t_params *params, va_list ap)
{
	if (params->asterisk == 1)
		params->width = va_arg(ap, int);
	if (params->width < 0)
	{
		params->minus = 1;
		params->zero = 0;
		params->width = -(params->width);
	}
	if (params->width >= 0 && params->asterisk != 1)
	{
		params->width = ft_atoi(&format[*index]);
		while (ft_isdigit(format[*index]))
			(*index)++;
	}
	params->asterisk = 0;
}

static void	check_precision(char *format, int *index, t_params *par, va_list ap)
{
	if (par->asterisk == 1)
	{
		par->precision = va_arg(ap, int);
		par->asterisk = 0;
		(*index) += 2;
	}
	else
	{
		(*index)++;
		par->precision = ft_atoi(&format[*index]);
		while (ft_isdigit(format[*index]))
			(*index)++;
	}
	if (par->zero == 1)
		par->zero1 = 1;
	if (par->precision < 0 && par -> zero == 1)
		par->zero = 1;
	else
		par->zero = 0;
	if (par->precision < 0)
		par->precision = -1;
}

int	ft_check_arg_params(char *format, t_params *params, va_list ap, int index)
{
	index++;
	while (ft_isflag(format[index]))
	{	
		check_flags(format, params, index);
		index++;
	}
	if (format[index] == '*')
	{
		index++;
		params->asterisk = 1;
	}
	if (ft_isdigit(format[index]) || params->asterisk == 1)
		check_width(format, &index, params, ap);
	if (format[index + 1] == '*')
		params->asterisk = 1;
	if (format[index] == '.')
		check_precision(format, &index, params, ap);
	if (ft_istype(format[index]))
		params->type = (unsigned char)format[index];
	return (++index);
}

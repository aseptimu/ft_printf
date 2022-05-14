/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/05 21:35:51 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

static int	proc_int_minus(t_params params, int tmp, unsigned int i, int length)
{
	print_flag_int(&params, &tmp);
	tmp += proc_precision(params.precision, length);
	ft_putnbr_uint(i, 1);
	tmp += proc_width(params.width, params.zero, tmp);
	return (tmp);
}

static int	proc_int_no_minus(t_params par, int tmp, unsigned int ui, int len)
{
	if (par.precision == -1 && ui == 0)
		par.precision = 1;
	if (par.zero == 1)
		print_flag_int(&par, &tmp);
	if (par.precision >= tmp)
		tmp += proc_width(par.width, par.zero, \
		par.space + par.plus + par.precision);
	else
		tmp += proc_width(par.width, par.zero, \
		tmp + par.plus + par.space);
	if (par.zero == 0)
		print_flag_int(&par, &tmp);
	tmp += proc_precision(par.precision, len);
	ft_putnbr_uint(ui, 1);
	return (tmp);
}

static unsigned int	proc_proc_int(t_params *par, int i, int *tmp, int *length)
{
	unsigned int	ui;

	if (i == 0)
		(*length)++;
	while (*tmp)
	{
		*tmp /= 10;
		(*length)++;
	}
	*tmp = *length;
	ui = i;
	if (i < 0)
	{
		par->plus = 0;
		par->space = 0;
		par->neg = 1;
		if (par->width >= par->precision && \
		par->precision > *tmp && par->minus == 0)
			par->width--;
		(*tmp)++;
		ui = i * -1;
	}
	return (ui);
}

static int	proc_zero(t_params params, int length)
{
	length = 0;
	params.zero = 0;
	if (params.space == 1 && params.precision <= 1 && params.width == 0)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	if (params.plus == 1 && params.minus == 1)
	{
		ft_putchar_fd('+', 1);
		length++;
	}
	length += proc_width(params.width, 0, params.plus);
	if (params.plus == 1 && params.minus == 0)
	{
		ft_putchar_fd('+', 1);
		length++;
	}
	return (length);
}

int	proc_integer(t_params params, int i)
{
	int				length;
	int				tmp;
	unsigned int	ui;

	length = 0;
	tmp = i;
	if (params.precision == 0 && i == 0)
		return (proc_zero(params, length));
	ui = proc_proc_int(&params, i, &tmp, &length);
	if (params.minus == 1)
		tmp = proc_int_minus(params, tmp, ui, length);
	if (params.minus == 0)
		tmp = proc_int_no_minus(params, tmp, ui, length);
	return (tmp);
}

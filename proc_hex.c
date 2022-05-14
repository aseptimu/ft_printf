/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:51:48 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/05 19:16:46 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	put_prefix(t_params *params, int flag, int *length)
{
	if (flag == 0)
		ft_putstr_fd("0x", 1);
	if (flag == 1)
		ft_putstr_fd("0X", 1);
	*length += 2;
	params->hash = 0;
}

static int	put_hex(t_params params, unsigned int hex, int length, int flag)
{
	int	tmp;

	tmp = length;
	if (hex == 0)
		params.hash = 0;
	if (params.hash == 2 && params.zero == 1)
		put_prefix(&params, flag, &length);
	if (params.width > 0 && params.minus == 0)
	{
		if (params.precision >= length)
			length += proc_width(params.width, params.zero, \
			params.precision + params.hash);
		else
			length += proc_width(params.width, params.zero, \
			length + params.hash);
	}
	if (params.hash == 2 && hex != 0 && params.zero == 0)
		put_prefix(&params, flag, &length);
	length += proc_precision(params.precision, tmp);
	ft_putnbr_hex(hex, flag);
	if (params.width > 0 && params.minus == 1)
		length += proc_width(params.width, params.zero, length);
	return (length);
}

int	proc_hexadecimal(t_params params, unsigned int hex)
{
	unsigned int	tmp;
	int				length;
	int				flag;

	flag = 0;
	length = 0;
	if (params.type == 'X')
		flag = 1;
	tmp = hex;
	if (hex == 0)
		length++;
	while (tmp)
	{
		tmp /= 16;
		length++;
	}
	if (params.precision == 0 && hex == 0)
	{
		tmp = proc_width(params.width, params.zero, 0);
		return (tmp);
	}
	length = put_hex(params, hex, length, flag);
	return (length);
}

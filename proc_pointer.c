/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:41:15 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/05 21:45:14 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_hex(unsigned long long ull, int flag)
{
	if (ull < 16)
	{
		if (ull >= 10 && flag == 0)
			ft_putchar_fd(ull - 10 + 'a', 1);
		else if (ull >= 10 && flag == 1)
			ft_putchar_fd(ull - 10 + 'A', 1);
		else
			ft_putnbr_fd(ull, 1);
	}
	else
	{
		ft_putnbr_hex(ull / 16, flag);
		ft_putnbr_hex(ull % 16, flag);
	}
}

static int	proc_null_ptr(t_params params, int length)
{
	int	index;
	int	w_len;

	index = 0;
	w_len = 3;
	if (params.precision == 0)
		w_len -= 1;
	if (params.minus == 0)
		length = proc_width(params.width, params.zero, w_len);
	if (params.precision != 0)
		ft_putstr_fd("0x0", 1);
	if (params.precision == 0)
		ft_putstr_fd("0x", 1);
	if (params.minus == 1)
		length = proc_width(params.width, params.zero, w_len);
	return (length + w_len);
}

int	proc_pointer(t_params params, void *pointer)
{
	int					length;
	unsigned long long	tmp;
	unsigned long long	ull;

	length = 0;
	if (pointer == NULL)
		return (proc_null_ptr(params, length));
	ull = (unsigned long long) pointer;
	length = 2;
	tmp = ull;
	if (ull == 0)
		length++;
	while (tmp)
	{
		tmp /= 16;
		length++;
	}
	if (params.width > 0 && params.minus == 0)
		length += proc_width(params.width, params.zero, length);
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(ull, 0);
	if (params.width > 0 && params.minus == 1)
		length += proc_width(params.width, params.zero, length);
	return (length);
}

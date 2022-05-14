/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:57:41 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/05 23:32:05 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	proc_s_output(t_params params, char *str, int *count)
{
	int	index;

	index = 0;
	while (str[index] && (index < params.precision || params.precision == -1))
	{
		ft_putchar_fd(str[index], 1);
		index++;
		(*count)++;
	}
}

int	proc_string(t_params params, char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!str)
		str = "(null)";
	if (params.minus == 1)
	{
		proc_s_output(params, str, &count);
	}
	if ((size_t)params.precision > ft_strlen(str))
		count += proc_width(params.width, params.zero, ft_strlen(str));
	else
		count += proc_width(params.width, params.zero, params.precision);
	if (params.minus == 0)
	{
		proc_s_output(params, str, &count);
	}
	return (count);
}

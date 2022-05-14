/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/08 20:13:44 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct param_lst
{
	int	type;
	int	space;
	int	minus;
	int	plus;
	int	hash;
	int	zero;
	int	width;
	int	precision;
	int	asterisk;
	int	neg;
	int	zero1;
}				t_params;

int		ft_printf(const char *format, ...);

int		ft_isflag(int c);
int		ft_istype(int c);

int		ft_check_arg_params(char *format, t_params *params, \
							va_list ap, int index);

int		ft_processing(t_params params, va_list ap);
int		proc_precision(int precision, int length);
int		proc_width(int width, int zero, int length);
int		proc_char(t_params params, char c);
int		proc_percent(t_params params, char c);

int		proc_string(t_params params, char *str);

int		proc_integer(t_params params, int i);

int		proc_uinteger(t_params params, unsigned int i);

int		proc_pointer(t_params params, void *pointer);
void	ft_putnbr_hex(unsigned long long ull, int flag);

int		proc_hexadecimal(t_params params, unsigned int hex);

void	ft_putnbr_uint(unsigned int n, int fd);
void	print_flag_int(t_params *par, int *tmp);
#endif
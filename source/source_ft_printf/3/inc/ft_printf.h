/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:48:23 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 20:54:45 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../helpers/helpers.h"

typedef struct	s_flags
{
	int	star;
	int	width;
	int	zero;
	int	blank;
	int	minus;
	int	type;
	int	dot;
}				t_flags;

int				ft_handle(int c, t_flags flags, va_list args);
int				ft_isconversion(int c);
int				ft_isflag(int c);

int				ft_handle_int(int i, t_flags flags);
int				ft_handle_width(int width, int minus, int zero);
int				ft_handle_char(char c, t_flags flags);
int				ft_handle_percent(t_flags flags);
int				ft_handle_pointer(unsigned long long num, t_flags flags);
int				ft_handle_string(char *str, t_flags flags);
int				ft_handle_base(unsigned int number, int lowercase,
		int base, t_flags flags);
int				ft_handle_uint(unsigned int number, t_flags flags);

t_flags			ft_star_flag(va_list argc, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_width_digit_flag(char c, t_flags flags);
int				ft_dot_flag(const char *str, int start,
		t_flags *flags, va_list args);

int				ft_printf(const char *fmt, ...);

#endif

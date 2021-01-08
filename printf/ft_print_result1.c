/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:35:33 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 16:31:17 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					ft_print_result(t_guide *guide, va_list ap)
{
	if (guide->format == '%')
		ft_percent(guide);
	else if (guide->format == 'c')
		ft_c(guide, ap);
	else if (guide->format == 'd' || guide->format == 'i')
		ft_di(guide, ap);
	else if (guide->format == 's')
		ft_s(guide, ap);
	else if (guide->format == 'p')
		ft_p(guide, ap);
	else if (guide->format == 'u')
		ft_u(guide, ap);
	else if (guide->format == 'x' || guide->format == 'X')
		ft_x(guide, ap);
}

void					ft_c(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				str;
	char				*surfix;

	prefix = ft_c_prefix(guide);
	str = va_arg(ap, int);
	surfix = ft_c_surfix(guide);
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putchar_fd(str, 1);
	g_print_len += 1;
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	free(prefix);
	free(surfix);
}

void					ft_di(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*surfix;
	char				*main_str;
	int					str;

	str = va_arg(ap, int);
	if (str >= 0)
		main_str = ft_di_main_str(guide, ft_nbrlen(str), str, ft_itoa(str));
	else
		main_str = ft_di_main_str(guide, ft_nbrlen(-1 * str), str,
													ft_itoa(-1 * str));
	prefix = ft_di_prefix(guide, ft_strlen(main_str), str);
	surfix = ft_di_surfix(guide, ft_strlen(main_str), str);
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putstr_fd(main_str, 1);
	g_print_len += (int)ft_strlen(main_str);
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	free(prefix);
	free(main_str);
	free(surfix);
}

void					ft_s(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*str;
	char				*surfix;

	str = ft_s_main_str(guide, va_arg(ap, char *));
	prefix = ft_s_prefix(guide, ft_strlen(str));
	surfix = ft_s_surfix(guide, ft_strlen(str));
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putstr_fd(str, 1);
	g_print_len += (int)ft_strlen(str);
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	free(prefix);
	free(surfix);
}

void					ft_p(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*surfix;
	char				*main_str;
	unsigned long long	str;

	str = va_arg(ap, unsigned long long);
	main_str = ft_p_main_str(guide, ft_pointlen(str),
										ft_make_d_to_p(str), str);
	prefix = ft_p_prefix(main_str, guide, ft_strlen(main_str), str);
	if (guide->precision == -1 || str == 0)
		free(main_str);
	if (guide->precision == -1 || str == 0)
		main_str = ft_calloc(1, 1);
	surfix = ft_p_surfix(guide, ft_strlen(prefix)
								+ ft_strlen(main_str), str);
	if (guide->check == 1 && guide->precision == 0 && guide->width == 0
			&& guide->blank == ' ' && guide->align == 'r' && str == 0)
	{
		ft_putstr_fd("0x", 1);
		g_print_len += 2;
		free(prefix);
		free(main_str);
		free(surfix);
	}
	ft_print_full(prefix, main_str, surfix);
}

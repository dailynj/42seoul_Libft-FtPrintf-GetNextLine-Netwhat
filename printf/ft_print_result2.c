/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:35:33 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 15:04:07 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					ft_u(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*surfix;
	char				*main_str;
	unsigned int		str;

	str = va_arg(ap, unsigned int);
	main_str = ft_u_main_str(guide, ft_u_nbrlen(str), str,
											ft_make_u_to_d(str));
	prefix = ft_u_prefix(guide, ft_strlen(main_str));
	surfix = ft_u_surfix(guide, ft_strlen(main_str));
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putstr_fd(main_str, 1);
	g_print_len += (int)ft_strlen(main_str);
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	//free(prefix);
	//free(main_str);
	//free(surfix);
}

void					ft_x(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*surfix;
	char				*main_str;
	unsigned int		str;

	str = va_arg(ap, unsigned int);
	main_str = ft_x_main_str(guide, ft_hexlen(str), str,
								ft_make_d_to_x(str, guide->format));
	prefix = ft_x_prefix(guide, ft_strlen(main_str));
	surfix = ft_x_surfix(guide, ft_strlen(main_str));
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putstr_fd(main_str, 1);
	g_print_len += (int)ft_strlen(main_str);
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	//free(prefix);
	//free(main_str);
	//free(surfix);
}

void					ft_percent(t_guide *guide)
{
	char				*prefix;
	char				str;
	char				*surfix;

	prefix = ft_c_prefix(guide);
	str = '%';
	surfix = ft_c_surfix(guide);
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putchar_fd(str, 1);
	g_print_len += 1;
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	//free(prefix);
	//free(surfix);
}

void					ft_print_full(char *prefix, char *main_str,
															char *surfix)
{
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	ft_putstr_fd(main_str, 1);
	g_print_len += (int)ft_strlen(main_str);
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
	//printf("prefix = <%s>\n", prefix);
	//printf("main_str = <%s>\n", main_str);
	//printf("surfix = <%s>\n", surfix);
	//free(prefix);
	//free(main_str);
	//free(surfix);
}

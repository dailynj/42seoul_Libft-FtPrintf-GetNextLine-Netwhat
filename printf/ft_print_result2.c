/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:35:33 by najlee            #+#    #+#             */
/*   Updated: 2021/01/06 17:00:09 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_u(t_guide *guide, va_list ap)
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

}

void		ft_x(t_guide *guide, va_list ap)
{
	char	*prefix;
	char	*surfix;
	char	*main_str;
	int		str;
	int		hex_len;
	
	str = va_arg(ap, int);
	main_str = ft_dec_to_hex(str);
	if (str >= 0)
		main_str = ft_di_main_str(guide, ft_hexlen(str), str,
													ft_dec_to_hex(str));
	else
		main_str = ft_di_main_str(guide, ft_hexlen(-1 * str), str,
												ft_dec_to_hex(-1 * str));
	prefix = ft_di_prefix(guide, ft_strlen(main_str), str);
	surfix = ft_di_surfix(guide, ft_strlen(main_str), str);
	
	ft_putstr_fd(prefix, 1);
	g_print_len += (int)ft_strlen(prefix);
	
	ft_putstr_fd(main_str, 1);
	g_print_len += (int)ft_strlen(main_str);
	
	ft_putstr_fd(surfix, 1);
	g_print_len += (int)ft_strlen(surfix);
}
/*
void		ft_x(t_guide *guide, va_list ap)
{
	char				*prefix;
	char				*surfix;
	char				*main_str;
	unsigned int		str;
	
	str = va_arg(ap, int);
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

	printf("\n\npre=<%s>\n", prefix);
	printf("\n\nstr=<%s>\n", main_str);
	printf("\n\nsur=<%s>\n", surfix);
}

void		ft_large_x(t_guide *guide, va_list ap)
	char				*prefix;
	unsigned int		str;
	char				*surfix;

	prefix = ft_x_prefix(guide);
	str = va_arg(ap, unsigned int);
	surfix = ft_x_surfix(guide);
	ft_putstr_fd(prefix, 1);
	// --------------------------------------print unsigned int
	ft_putstr_fd(surfix, 1);
}

void		ft_large_x(t_guide *guide, va_list ap)
{
	char				*prefix;
	unsigned int		str;
	char				*surfix;

	prefix = ft_large_x_prefix(guide);
	str = va_arg(ap, unsigned int);
	surfix = ft_large_x_surfix(guide);
	ft_putstr_fd(prefix, 1);
	// --------------------------------------print unsigned int
	ft_putstr_fd(surfix, 1);
}
*/
char	*ft_blank_str(int len, char blank)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (i < len)
	{
		tmp[i] = blank;
		i++;
	}
	return (tmp);
}

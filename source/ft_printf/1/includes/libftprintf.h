/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:32:42 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 16:36:58 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct		s_info
{
	int		align;
	char	empty;
	int		sharp;
	char	sign;
	int		width;
	int		precision;
	char	format;
}					t_info;

extern int			g_printsize;

int					ft_printf(const char *s, ...);
void				ft_print_pretty(t_info *info, va_list ap);
int					ft_make_info(const char *s,
								size_t i, t_info *info, va_list ap);

int					ft_deal_flag(const char *s, size_t i, t_info *info);
int					ft_deal_width(const char *s,
								size_t i, t_info *info, va_list ap);
int					ft_deal_precision(const char *s,
								size_t i, t_info *info, va_list ap);
int					ft_deal_format(const char *s, size_t i, t_info *info);

void				ft_init_info(t_info *info);

char				*ft_make_format(t_info *info, va_list ap);
char				*ft_format_d(t_info *info, va_list ap);
char				*ft_format_u(va_list ap);
char				*ft_format_s(va_list ap);
char				*ft_format_c(va_list ap);
char				*ft_format_x(va_list ap, char c);
char				*ft_format_p(va_list ap);

char				*ft_make_prefix(t_info *info, char *str);
char				*ft_make_prefix_xu(t_info *info, char *str);
char				*ft_make_prefix_c(t_info *info, char *str);
char				*ft_make_prefix_s(t_info *info, char *str);
void				ft_put_aligned(t_info *info, char *str, char *pre);
char				*ft_make_prefix_di(t_info *info, char *str);
char				*ft_pre_wp_comb(t_info *info, int len, char *str);
char				*ft_pre_only_sign(t_info *info);
char				*ft_pre_sign_zero_w(t_info *info, int len);
char				*ft_pre_sign_zero_p(t_info *info, int len);
char				*ft_pre_space_sign_zero(t_info *info, int len, char *str);
char				*ft_make_prefix_p(t_info *info, char *str);
char				*ft_pre_wp_comb_p(t_info *info, int len, char *str);
char				*ft_pre_only_sign_p(void);
char				*ft_pre_sign_zero_w_p(t_info *info, int len);
char				*ft_pre_sign_zero_p_p(t_info *info, int len);
char				*ft_pre_space_sign_zero_p(t_info *info, int len, char *str);
void				ft_set_p_zerox(int idx, char *ret);
#endif

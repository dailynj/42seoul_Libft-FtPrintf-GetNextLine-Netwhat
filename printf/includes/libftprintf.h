/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:16:11 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 14:48:07 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>  //remove
typedef struct	s_guide
{
	char		align;
	char		blank;
	int			width;
	int			precision;
	int			sign;
	char		format;
	int			check;
}				t_guide;

extern int		g_print_len;

int				ft_printf(const char *s, ...);
void			ft_init_flag(t_guide *guide);
int				ft_fill_flag(const char *str, int i, t_guide *guide);
int				ft_fill_width(const char *str,
									int i, t_guide *guide, va_list ap);
int				ft_fill_precision(const char *str,
									int i, t_guide *guide, va_list ap);
int				ft_fill_format(const char *str, int i, t_guide *guide);
int				ft_fill_guide(const char *str,
									int i, t_guide *guide, va_list ap);
void			ft_print_result(t_guide *guide, va_list ap);
void			ft_c(t_guide *guide, va_list ap);
void			ft_di(t_guide *guide, va_list ap);
void			ft_s(t_guide *guide, va_list ap);
void			ft_p(t_guide *guide, va_list ap);
void			ft_u(t_guide *guide, va_list ap);
void			ft_x(t_guide *guide, va_list ap);
void			ft_large_x(t_guide *guide, va_list ap);

char			*ft_c_prefix(t_guide *guide);
char			*ft_c_surfix(t_guide *guide);
char			*ft_di_prefix(t_guide *guide, int nbrlen, int num);
char			*ft_di_main_str(t_guide *guide, int nbrlen, int num,
																char *str);
char			*ft_di_surfix(t_guide *guide, int nbrlen, int num);
char			*ft_di_main_str_negative(int num, t_guide *guide,
													int nbrlen, char *str);
char			*ft_di_main_str_none(int num, t_guide *guide,
													int nbrlen, char *str);

char			*ft_s_prefix(t_guide *guide, int num);
char			*ft_s_main_str(t_guide *guide, char *str);
char			*ft_s_surfix(t_guide *guide, int num);

char			*ft_p_prefix(char *str, t_guide *guide, int nbrlen,
													unsigned long long num);
char			*ft_p_main_str(t_guide *guide, int nbrlen, char *str,
												unsigned long long num);
char			*ft_p_surfix(t_guide *guide, int nbrlen,
													unsigned long long num);
char			*ft_p_main_str_negative(t_guide *guide,	int nbrlen, char *str);
char			*ft_p_main_str_none(t_guide *guide, int nbrlen, char *str);

char			*ft_u_prefix(t_guide *guide, int nbrlen);
char			*ft_u_main_str(t_guide *guide, int nbrlen, unsigned int num,
																char *str);
char			*ft_u_surfix(t_guide *guide, int nbrlen);
char			*ft_u_main_str_negative(t_guide *guide,	int nbrlen, char *str);
char			*ft_u_main_str_none(t_guide *guide, int nbrlen, char *str);

char			*ft_x_prefix(t_guide *guide, int nbrlen);
char			*ft_x_main_str(t_guide *guide, int nbrlen, unsigned int num,
																char *str);
char			*ft_x_surfix(t_guide *guide, int nbrlen);
char			*ft_x_main_str_negative(t_guide *guide,	int nbrlen, char *str);
char			*ft_x_main_str_none(t_guide *guide, int nbrlen, char *str);
void			ft_percent(t_guide *guide);
void			ft_print_full(char *prefix, char *main_str, char *surfix);

char			*ft_blank_str(int len, char blank);
int				ft_nbrlen(int n);
int				ft_u_nbrlen(unsigned int n);
char			*ft_strcat(char *dest, char *src);
int				ft_cal_precision(const char *str, int i, t_guide *guide);

char			*ft_make_u_to_d(unsigned int num);
char			*ft_make_d_to_x(unsigned int num, char c);
int				ft_hexlen(unsigned int num);
int				ft_pointlen(unsigned long long num);
char			*ft_make_d_to_p(unsigned long long num);

#endif

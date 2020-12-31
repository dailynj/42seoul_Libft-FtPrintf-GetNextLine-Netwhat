/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:16:11 by najlee            #+#    #+#             */
/*   Updated: 2020/12/31 13:18:05 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
#include <stdio.h> //remove
typedef struct	s_guide
{
	char		align;
	char		blank;
	int			width;
	int			precision;
	char		format;
}				t_guide;

extern int		g_print_len;

void	ft_printf_guide(t_guide *guide); //remove
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
char			*ft_di_prefix(t_guide *guide);
char			*ft_di_surfix(t_guide *guide);
char			*ft_s_prefix(t_guide *guide);
char			*ft_s_surfix(t_guide *guide);
char			*ft_p_prefix(t_guide *guide);
char			*ft_p_surfix(t_guide *guide);
char			*ft_u_prefix(t_guide *guide);
char			*ft_u_surfix(t_guide *guide);
char			*ft_x_prefix(t_guide *guide);
char			*ft_x_surfix(t_guide *guide);
char			*ft_large_x_prefix(t_guide *guide);
char			*ft_large_x_surfix(t_guide *guide);

char			*ft_blank_str(int len, char blank);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:16:11 by najlee            #+#    #+#             */
/*   Updated: 2020/12/30 12:59:55 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_guide
{
	char		align;
	char		blank;
	int			width;
	int			precision;
	char		format;
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

#endif

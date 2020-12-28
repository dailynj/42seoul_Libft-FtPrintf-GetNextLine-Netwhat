/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:16:11 by najlee            #+#    #+#             */
/*   Updated: 2020/12/28 21:48:36 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

typedef struct	s_guide
{
	char		*flag;
	char 		*width;
	char		*precision;
	char		format;
//	void		*data;
}				t_guide;

extern int		g_printlen;

int				ft_printf(const char *s, ...);

#endif

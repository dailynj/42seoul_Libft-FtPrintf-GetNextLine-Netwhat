/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:35:33 by najlee            #+#    #+#             */
/*   Updated: 2020/12/30 18:41:45 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/*
void		ft_u(t_guide *guide, va_list ap)
{
	char				*prefix;
	unsigned int		str;
	char				*surfix;

	prefix = ft_u_prefix(guide);
	str = va_arg(ap, unsigned int);
	surfix = ft_u_surfix(guide);
	ft_putstr_fd(prefix, 1);
	// --------------------------------------print unsigned int
	ft_putstr_fd(surfix, 1);
}

void		ft_x(t_guide *guide, va_list ap)
{
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:21:39 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 23:48:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_s_prefix(t_guide *guide, int num)
{
	char	*str;

	if (guide->align == 'r' && guide->width > num)
		return (str = ft_blank_str(guide->width - num, guide->blank));
	return (str = ft_calloc(1, 1));
}

char		*ft_s_main_str(t_guide *guide, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (guide->sign > 0 && guide->precision >= 0
								&& guide->precision < (int)ft_strlen(str))
	{
		if (!(tmp = ft_calloc(guide->precision + 1, 1)))
			return (NULL);
		while ((i < guide->precision) && (i < (int)ft_strlen(str)))
		{
			tmp[i] = str[i];
			i++;
		}
		free(str);
		return (tmp);
	}
	return (str);
}

char		*ft_s_surfix(t_guide *guide, int num)
{
	char	*str;

	if (guide->align == 'l' && guide->width > num)
		return (str = ft_blank_str(guide->width - num, ' '));
	return (str = ft_calloc(1, 1));
}

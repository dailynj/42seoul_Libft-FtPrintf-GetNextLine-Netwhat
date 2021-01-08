/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 20:37:39 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_x_prefix(t_guide *guide, int nbrlen)
{
	char	*str;

	if (guide->width > nbrlen && guide->align == 'r')
		return (str = ft_blank_str(guide->width - nbrlen, ' '));
	return (str = ft_calloc(1, 1));
}

char		*ft_x_main_str(t_guide *guide, int nbrlen, unsigned int num,
																char *str)
{
	char	*str1;

	if (num == 0 && (guide->precision == 0 || (guide->check == 1 &&
												guide->precision == -1)))
		return (str = ft_calloc(1, 1));
	if (guide->precision >= 0 && guide->sign < 0)
		str = ft_x_main_str_negative(guide, nbrlen, str);
	else if (guide->precision >= 0 && guide->sign > 0)
	{
		if (guide->precision > nbrlen)
		{
			str1 = ft_blank_str(guide->precision - nbrlen, '0');
			str = ft_strcat(str1, str);
			free(str1);
			return (str);
		}
	}
	else
		str = ft_x_main_str_none(guide, nbrlen, str);
	return (str);
}

char		*ft_x_surfix(t_guide *guide, int nbrlen)
{
	char	*str;

	if (guide->width > nbrlen && guide->align == 'l')
		return (str = ft_blank_str(guide->width - nbrlen, ' '));
	return (str = ft_calloc(1, 1));
}

char		*ft_x_main_str_negative(t_guide *guide, int nbrlen, char *str)
{
	char	*str1;

	if (guide->width > nbrlen && guide->blank == '0' &&
											guide->align == 'r')
	{
		str1 = ft_blank_str(guide->width - nbrlen, '0');
		str = ft_strcat(str1, str);
		free(str1);
		return (str);
	}
	return (str);
}

char		*ft_x_main_str_none(t_guide *guide, int nbrlen, char *str)
{
	char	*str1;

	if (guide->width > nbrlen)
	{
		if (guide->align == 'l')
		{
			str1 = ft_blank_str(guide->width - nbrlen, ' ');
			str = ft_strcat(str, str1);
			free(str1);
			return (str);
		}
		else
		{
			str1 = ft_blank_str(guide->width - nbrlen, guide->blank);
			str = ft_strcat(str1, str);
			free(str1);
			return (str);
		}
	}
	return (str);
}

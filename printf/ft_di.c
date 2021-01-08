/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 16:11:15 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_di_prefix(t_guide *guide, int nbrlen, int num)
{
	char	*tmp;
	char	*str;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num == -2147483648)
		str = ft_calloc(1, 1);
	else if (guide->precision != -1 && num < 0)
	{
		if (guide->width > nbrlen && guide->align == 'r')
		{
			str = ft_strcat(ft_blank_str(guide->width -
											nbrlen - 1, ' '), tmp);
			free(tmp);
			return (str);
		}
		str = ft_strdup(tmp);
	}
	else if (guide->width > nbrlen && guide->align == 'r')
		str = ft_blank_str(guide->width - nbrlen, ' ');
	else
		str = ft_calloc(1, 1);
	free(tmp);
	return (str);
}

char		*ft_di_main_str(t_guide *guide, int nbrlen, int num, char *str)
{
	if (num == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (num == 0 && (guide->precision == 0 || (guide->check == 1 &&
												guide->precision == -1)))
		return (str = ft_calloc(1, 1));
	if (guide->precision >= 0 && guide->sign < 0)
		return (str = ft_di_main_str_negative(num, guide, nbrlen, str));
	else if (guide->precision >= 0 && guide->sign > 0)
	{
		if (guide->precision > nbrlen)
			return (str = ft_strcat(ft_blank_str(guide->precision
											- nbrlen, '0'), str));
	}
	else
		return (str = ft_di_main_str_none(num, guide, nbrlen, str));
	return (str);
}

char		*ft_di_surfix(t_guide *guide, int nbrlen, int num)
{
	char *str;

	if (num < 0)
	{
		if (guide->width > nbrlen && guide->align == 'l' &&
												guide->precision < 0)
			return (str = ft_blank_str(guide->width - nbrlen, ' '));
		if (guide->width > nbrlen && guide->align == 'l')
			return (str = ft_blank_str(guide->width - nbrlen - 1, ' '));
	}
	if (guide->width > nbrlen && guide->align == 'l')
		return (str = ft_blank_str(guide->width - nbrlen, ' '));
	return (str = ft_calloc(1, 1));
}

char		*ft_di_main_str_negative(int num, t_guide *guide,
												int nbrlen, char *str)
{
	if (num >= 0)
	{
		if (guide->width > nbrlen && guide->blank == '0' &&
												guide->align == 'r')
			return (str = ft_strcat(ft_blank_str(guide->width
											- nbrlen, '0'), str));
	}
	else
	{
		if (guide->width > nbrlen && guide->blank == '0' &&
												guide->align == 'r')
			return (str = ft_strcat(ft_blank_str(guide->width
											- nbrlen - 1, '0'), str));
	}
	return (str);
}

char		*ft_di_main_str_none(int num, t_guide *guide, int nbrlen,
													char *str)
{
	char	*tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num >= 0 && guide->width > nbrlen)
	{
		if (guide->align == 'l')
			str = ft_strcat(str, ft_blank_str(guide->width - nbrlen, ' '));
		else
			str = ft_strcat(ft_blank_str(guide->width
									- nbrlen, guide->blank), str);
	}
	else if (num < 0 && guide->blank == '0' && guide->width > nbrlen
												&& guide->align == 'r')
		str = ft_strcat(tmp, ft_strcat(ft_blank_str(guide->width
									- nbrlen - 1, guide->blank), str));
	else if (num < 0 && guide->blank == ' ' && guide->width > nbrlen
													&& guide->align == 'r')
		str = ft_strcat(ft_strcat(ft_blank_str(guide->width
								- nbrlen - 1, guide->blank), tmp), str);
	else if (num < 0)
		str = ft_strcat(tmp, str);
	free(tmp);
	return (str);
}

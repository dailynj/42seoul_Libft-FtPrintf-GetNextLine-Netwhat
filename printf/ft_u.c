/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/05 23:17:05 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_u_prefix(t_guide *guide, int nbrlen, int num)
{
	char	*tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (guide->precision != -1 && num < 0)
	{
		if (guide->width > nbrlen && guide->align == 'r')
		{
			return (ft_strcat(ft_blank_str(guide->width -
											nbrlen - 1, ' '), tmp));
		}
		return (tmp);
	}
	if (guide->width > nbrlen && guide->align == 'r')
		return (ft_blank_str(guide->width - nbrlen, ' '));
	return (ft_calloc(1, 1));
}

char		*ft_u_main_str(t_guide *guide, int nbrlen, int num, char *str)
{
	char	*tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num == 0 && (guide->precision == 0 || (guide->check == 1 &&
												guide->precision == -1)))
		return (ft_calloc(1, 1));
	if (guide->precision >= 0 && guide->sign < 0)
		str = ft_u_main_str_negative(num, guide, nbrlen, str);
	else if (guide->precision >= 0 && guide->sign > 0)
	{
		if (guide->precision > nbrlen)
			return (ft_strcat(ft_blank_str(guide->precision
											- nbrlen, '0'), str));
	}
	else
		str = ft_u_main_str_none(num, guide, nbrlen, str);
	return (str);
}

char		*ft_u_surfix(t_guide *guide, int nbrlen, int num)
{
	if (num < 0)
	{
		if (guide->width > nbrlen && guide->align == 'l' &&
												guide->precision < 0)
			return (ft_blank_str(guide->width - nbrlen, ' '));
		if (guide->width > nbrlen && guide->align == 'l')
			return (ft_blank_str(guide->width - nbrlen - 1, ' '));
	}
	if (guide->width > nbrlen && guide->align == 'l')
		return (ft_blank_str(guide->width - nbrlen, ' '));
	return (ft_calloc(1, 1));
}

char		*ft_u_main_str_negative(int num, t_guide *guide,
												int nbrlen, char *str)
{
	if (num >= 0)
	{
		if (guide->width > nbrlen && guide->blank == '0' &&
												guide->align == 'r')
			return (ft_strcat(ft_blank_str(guide->width
											- nbrlen, '0'), str));
	}
	else
	{
		if (guide->width > nbrlen && guide->blank == '0' &&
												guide->align == 'r')
			return (ft_strcat(ft_blank_str(guide->width
											- nbrlen - 1, '0'), str));
	}
	return (str);
}

char		*ft_u_main_str_none(int num, t_guide *guide, int nbrlen,
													char *str)
{
	char	*tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num >= 0 && guide->width > nbrlen)
	{
		if (guide->align == 'l')
			return (ft_strcat(str, ft_blank_str(guide->width
												- nbrlen, ' ')));
		else
			return (ft_strcat(ft_blank_str(guide->width
									- nbrlen, guide->blank), str));
	}
	else if (num < 0 && guide->blank == '0' && guide->width > nbrlen
												&& guide->align == 'r')
		return (ft_strcat(tmp, ft_strcat(ft_blank_str(guide->width
									- nbrlen - 1, guide->blank), str)));
	else if (num < 0 && guide->blank == ' ' && guide->width > nbrlen
													&& guide->align == 'r')
		return (ft_strcat(ft_strcat(ft_blank_str(guide->width
								- nbrlen - 1, guide->blank), tmp), str));
	else if (num < 0)
		str = ft_strcat(tmp, str);
	return (str);
}

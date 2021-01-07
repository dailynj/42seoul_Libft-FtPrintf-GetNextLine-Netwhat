/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/07 17:21:14 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_p_prefix(char *str, t_guide *guide, int nbrlen, unsigned long long num)
{
	(void)num;
	char	*tmp;

	if (!(tmp = ft_calloc(3, sizeof(char))))
		return (NULL);
	tmp[0] = '0';
	tmp[1] = 'x';
	if (guide->precision == -1)
	{
		if (guide->width - 2 > nbrlen)
		{
			if (guide->align == 'l')
				return (ft_strcat(tmp, ft_strcat(str, ft_blank_str(guide->width - 2 -nbrlen, ' '))));
			else
			{
				if (guide->blank == '0')
					return (ft_strcat(tmp, ft_strcat(ft_blank_str
									(guide->width - 2 -nbrlen, '0'), str)));
				else
					return (ft_strcat(ft_strcat(ft_blank_str
								(guide->width - 2 -nbrlen, ' '), tmp), str));
			}
		}
	}
	
	if ((guide->width - 2) > nbrlen && guide->align == 'r')
		return (ft_strcat(ft_blank_str(guide->width - 2 - nbrlen, ' '), tmp));
	if (num == 0 || guide->precision == -1)
		return (ft_strcat(tmp, str));
	return (tmp);
}

char		*ft_p_main_str(t_guide *guide, int nbrlen, unsigned long long num,
																char *str)
{
	(void)num;
	if (num == 0 && (guide->precision == 0 || (guide->check == 1 &&
												guide->precision == -1)))
		return (ft_calloc(1, 1));
	if (guide->precision >= 0 && guide->sign < 0)
		str = ft_p_main_str_negative(guide, nbrlen, str);
	else if (guide->precision >= 0 && guide->sign > 0)
	{
		if (guide->precision > nbrlen)
			return (ft_strcat(ft_blank_str(guide->precision
											- nbrlen, '0'), str));
	}
	//else
		//return (ft_calloc(1, 1));
		//	str = ft_p_main_str_none(guide, nbrlen, str);
	return (str);
}

char		*ft_p_surfix(t_guide *guide, int nbrlen, unsigned long long num)
{
	if (guide->precision == 0 && guide->check == 1)
		return (ft_blank_str(guide->width - nbrlen, ' '));
	if (num == 0 && guide->precision == -1)
		return (ft_calloc(1, 1));
	if ((guide->width- 2) > nbrlen && guide->align == 'l')
		return (ft_blank_str(guide->width - 2 - nbrlen, ' '));
	return (ft_calloc(1, 1));
}

char		*ft_p_main_str_negative(t_guide *guide,	int nbrlen, char *str)
{
	if (guide->width > nbrlen && guide->blank == '0' &&
											guide->align == 'r')
		return (ft_strcat(ft_blank_str(guide->width
										- nbrlen, '0'), str));
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 19:37:04 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_p_prefix(char *str, t_guide *guide, int nbrlen,
												unsigned long long num)
{
	char	*tmp;

	tmp = ft_strdup2("0x");
	if ((guide->precision == -1) && ((guide->width - 2) > nbrlen))
	{
		str = ft_p_precision_none(guide, nbrlen, str, tmp);
		free(tmp);
		return (str);
	}
	if ((guide->width - 2) > nbrlen && guide->align == 'r')
	{
		str = ft_strcat(ft_blank_str(guide->width - 2 - nbrlen, ' '), tmp);
		free(tmp);
		return (str);
	}
	if (num == 0 || guide->precision == -1)
	{
		str = ft_strcat(tmp, str);
		free(tmp);
		return (str);
	}
	return (tmp);
}

char		*ft_p_main_str(t_guide *guide, int nbrlen, char *str,
												unsigned long long num)
{
	char	*str1;

	if (num == 0 && (guide->precision == 0 || (guide->check == 1 &&
												guide->precision == -1)))
		return (str = ft_calloc(1, 1));
	if (guide->precision >= 0 && guide->sign < 0)
		return (str = ft_p_main_str_negative(guide, nbrlen, str));
	else if (guide->precision >= 0 && guide->sign > 0)
	{
		if (guide->precision > nbrlen)
		{
			str1 = ft_blank_str(guide->precision - nbrlen, '0');
			str = ft_strcat(ft_blank_str(guide->precision - nbrlen, '0'), str);
			free(str1);
			return (str);
		}
	}
	return (str);
}

char		*ft_p_surfix(t_guide *guide, int nbrlen, unsigned long long num)
{
	char *str;

	if (guide->precision == 0 && guide->check == 1)
		return (str = ft_blank_str(guide->width - nbrlen, ' '));
	if (num == 0 && guide->precision == -1)
		return (str = ft_calloc(1, 1));
	if ((guide->width - 2) > nbrlen && guide->align == 'l')
		return (str = ft_blank_str(guide->width - 2 - nbrlen, ' '));
	return (str = ft_calloc(1, 1));
}

char		*ft_p_main_str_negative(t_guide *guide, int nbrlen, char *str)
{
	char	*str1;

	if (guide->width > nbrlen && guide->blank == '0' && guide->align == 'r')
	{
		str1 = ft_blank_str(guide->width - nbrlen, '0');
		str = ft_strcat(ft_blank_str(guide->width - nbrlen, '0'), str);
		free(str1);
		return (str);
	}
	return (str);
}

char		*ft_p_precision_none(t_guide *guide,
							int nbrlen, char *str, char *tmp)
{
	char	*str1;
	char	*str2;

	if (guide->align == 'l')
	{
		str1 = ft_blank_str(guide->width - 2 - nbrlen, ' ');
		str = ft_strcat(tmp, ft_strcat(str, str1));
		free(str1);
		return (str);
	}
	if (guide->blank == '0')
	{
		str1 = ft_blank_str(guide->width - 2 - nbrlen, '0');
		str2 = ft_strcat(str1, str);
		str = ft_strcat(tmp, str2);
		free(str1);
		free(str2);
		return (str);
	}
	else
	{
		str1 = ft_blank_str(guide->width - 2 - nbrlen, ' ');
		str2 = ft_strcat(str1, tmp);
		str = ft_strcat(str2, str);
		free(str1);
		free(str2);
		return (str);
	}
}

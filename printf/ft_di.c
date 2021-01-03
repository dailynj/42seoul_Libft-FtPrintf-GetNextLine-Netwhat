/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2021/01/03 19:49:23 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_di_prefix(t_guide *guide, int nbrlen, int num)
{
	char *tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num > 0)
	{
		if (guide->align == 'r' && guide->width > nbrlen)
		{
			if (guide->precision >= 0)
				return (ft_blank_str(guide->width - nbrlen, ' '));
			else
				return (ft_blank_str(guide->width - nbrlen, '0'));
		}
		return (ft_calloc(1, 1));
	}
	else
	{
		if (guide->align == 'r' && guide->width > nbrlen)
		{
			if (guide->blank == '0')
				return (ft_strcat(tmp, ft_blank_str(guide->width - nbrlen - 1,
															guide->blank)));
			else if (guide->blank == ' ')
				return (ft_strcat(ft_blank_str(guide->width - nbrlen - 1,
														guide->blank), tmp));
		}
		return (tmp);
	}
}

char	*ft_di_main_str(t_guide *guide, int nbrlen, int num, char *str)
{	
	(void)num;
	if (guide->precision < nbrlen)
		return (str);
	
	//if (num > 0)
		return (ft_strcat(ft_blank_str(guide->precision - nbrlen, '0'), str));
	//else
	//	return (ft_strcat(ft_blank_str(guide->precision - nbrlen - 1, '0'),
	//																	str));
}

char	*ft_di_surfix(t_guide *guide, int nbrlen, int num)
{
	if (num > 0)
	{
		if (guide->align == 'l')
		{
			if (guide->width > nbrlen && guide->precision > nbrlen)
				return (ft_blank_str(guide->width - guide->precision, ' '));
			else if (guide->width > nbrlen && guide->precision <= nbrlen)
				return (ft_blank_str(guide->width - nbrlen, ' '));
		}
	}
	else
	{
		if (guide->align == 'l')
		{
			if (guide->width > nbrlen && guide->precision > nbrlen)
				return (ft_blank_str(guide->width - guide->precision - 1, ' '));
			else if (guide->width > nbrlen && guide->precision <= nbrlen)
				return (ft_blank_str(guide->width - nbrlen - 1, ' '));
		}
	}
	return (ft_calloc(1, 1));
}

/*
char	*ft_di_prefix(t_guide *guide, int nbrlen, int num)
{
	char *tmp;

	if (!(tmp = ft_calloc(2, sizeof(char))))
		return (NULL);
	tmp[0] = '-';
	if (num < 0)
	{
		if (guide->width > nbrlen || guide->blank == '0')
		{	
			if (guide->align == 'l')
				return (tmp);
			return (ft_strcat(tmp, ft_blank_str(guide->width - nbrlen ,'0')));
		}
		if (guide->width > nbrlen || guide->blank == ' ')
		{
			if (guide->align == 'l')
				return (tmp);
			return (ft_strcat(ft_blank_str(guide->width - nbrlen ,' '), tmp));
		}
		
		if (guide->precision >= guide->width)
			return (ft_strcat(tmp, ft_blank_str(guide->precision
												- nbrlen + 1, '0')));
		else
		{
			if (guide->precision > nbrlen)
				return (ft_strcat(ft_strcat(ft_blank_str(guide->width -
					guide->precision - 1 ,' '), tmp),
					ft_blank_str(guide->precision - nbrlen + 1, '0')));
			else
				return (ft_strcat(ft_blank_str(guide->width -
					nbrlen ,' '), tmp));
		}
	}
	if (guide->precision < 0)
		return (ft_blank_str(guide->width - nbrlen, ' '));
	if (guide->width < nbrlen)
		return (ft_calloc(1, 1));
	if (guide->width < guide->precision)
		return (ft_blank_str(guide->precision - nbrlen, '0'));
	if (guide->align == 'l')
		return (ft_calloc(1, 1));
	return (ft_blank_str(guide->width - nbrlen, guide->blank));
}

char	*ft_di_surfix(t_guide *guide, int nbrlen, int num)
{
	if (guide->width < guide->precision)
	{
		if (num < 0)
			return (ft_blank_str(guide->precision - guide->width - 1, ' '));
		else
			return (ft_blank_str(guide->precision - guide->width, ' '));
	}
	if (guide->width < nbrlen)
		return (ft_calloc(1, 1));
	if (guide->width <= guide->precision)
		return (ft_calloc(1, 1));
	if (guide->align == 'r')
		return (ft_calloc(1, 1));
	return (ft_blank_str(guide->width - nbrlen, ' '));
}
*/
char	*ft_strcat(char *dest, char *src)
{
	int i;
	int len;
	char *tmp;

	i = 0;
	len = ft_strlen(dest) + ft_strlen(src);
	if (!(tmp = malloc(len + 1)))
		return (NULL);
	while (*dest)
	{
		tmp[i] = *dest;
		i++;
		dest++;
	}
	while (*src)
	{
		tmp[i] = *src;
		i++;
		src++;
	}
	tmp[i] = '\0';
	return (tmp);
}

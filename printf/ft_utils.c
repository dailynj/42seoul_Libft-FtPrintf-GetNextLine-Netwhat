/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:09:43 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 13:07:49 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_nbrlen(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int			ft_u_nbrlen(unsigned int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		len;
	char	*tmp;

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
	//if (!src)
//		free(src);
	return (tmp);
}

char		*ft_blank_str(int len, char blank)
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

int			ft_cal_precision(const char *str, int i, t_guide *guide)
{
	int		precision;

	precision = 0;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			precision = (precision * 10) + (str[i++] - '0');
		guide->precision = precision;
	}
	return (i);
}

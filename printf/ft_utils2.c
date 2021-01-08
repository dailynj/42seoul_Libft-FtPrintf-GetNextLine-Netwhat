/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:38:18 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 19:40:42 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						ft_hexlen(unsigned int num)
{
	unsigned int		tmp;
	unsigned int		len;

	len = 0;
	tmp = num;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	return (len);
}

int						ft_pointlen(unsigned long long num)
{
	unsigned long long	tmp;
	unsigned long long	len;

	len = 0;
	tmp = num;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	return (len);
}

char		*ft_strdup2(const char *src)
{
	char	*tmp;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	if (!(tmp = malloc(src_len + 1)))
		return (0);
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	//free((char *)src);
	return (tmp);
}

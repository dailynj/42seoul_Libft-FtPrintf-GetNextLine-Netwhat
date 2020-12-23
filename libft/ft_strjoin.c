/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:50:02 by najlee            #+#    #+#             */
/*   Updated: 2020/12/24 02:31:18 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
	{
	}
	return (tmp);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if (!(tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	if (!s1)
	{
		ft_strcpy(tmp, (char *)s2);
		tmp[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	}
	else if (s1 && s2)
	{
		ft_strcpy(tmp, (char *)s1);
		ft_strcat(tmp, (char *)s2);
		tmp[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	}
	else
	{
		tmp[0] = '\0';
	}
	return (tmp);
}

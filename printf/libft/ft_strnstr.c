/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:11:22 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 22:12:14 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			find_str(const char *str, const char *to_find, int n)
{
	str += n;
	while (*to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	if (!n)
		return (0);
	if (!*str)
		return (0);
	while ((str[i] != 0) && (i <= (n - ft_strlen(to_find))))
	{
		if (find_str(str, to_find, i) == 1)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

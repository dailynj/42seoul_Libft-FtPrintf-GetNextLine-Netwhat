/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:35:07 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 14:37:54 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_isincluded(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	if (s1 == 0)
		return (0);
	len = 0;
	while (s1[len] != '\0')
		len++;
	start = 0;
	while (s1[start] != '\0' && ft_isincluded(set, s1[start]) != 0)
		start++;
	end = len;
	while (end > start && ft_isincluded(set, s1[end - 1]) != 0)
		end--;
	result = malloc(sizeof(char) * (end - start + 1));
	if (result == 0)
		return (0);
	len = 0;
	while (start < end)
		result[len++] = s1[start++];
	result[len] = '\0';
	return (result);
}

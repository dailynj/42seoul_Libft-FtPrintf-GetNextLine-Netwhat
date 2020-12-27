/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:34:33 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 14:34:38 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_substr(const char *s,\
		unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	if (s == 0)
		return (0);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		if (i >= start)
		{
			result[j] = s[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

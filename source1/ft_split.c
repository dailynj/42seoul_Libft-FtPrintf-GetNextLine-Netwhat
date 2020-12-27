/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:35:39 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 14:35:34 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_isincluded(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (s == 0)
		return (0);
	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

static	char			**ft_free(char ***result, unsigned int count)
{
	unsigned int	i;

	i = count;
	while (i != 0)
	{
		free((*result)[--i]);
	}
	free(*result);
	return (0);
}

char					**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;
	unsigned int	count;
	unsigned int	j;

	result = malloc(sizeof(char *) * (ft_isincluded(s, c) + 2));
	if (result == 0 || s == 0)
		return (0);
	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j != i)
		{
			result[count] = ft_substr(s, j, (i--) - j);
			if (result[count] == 0)
				return (ft_free(&result, count));
			count++;
		}
	}
	result[count] = 0;
	return (result);
}

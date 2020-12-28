/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:38:24 by najlee            #+#    #+#             */
/*   Updated: 2020/12/28 12:55:40 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t		ft_wordcnt(const char *s, char d)
{
	size_t			cnt;
	size_t			i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != d)
		{
			cnt++;
			while (s[i] && s[i] != d)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char			*ft_worddup(const char *s, char d)
{
	size_t			len;
	char			*ptr;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char				**ft_split(const char *s, char d)
{
	char			**ptr;
	size_t			len;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	len = ft_wordcnt(s, d);
	if (!(ptr = (char **)ft_calloc(len + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s[j])
	{
		if (s[j] != d)
		{
			if (!(ptr[i++] = ft_worddup(&(s[j]), d)))
				return (ft_freeall(ptr));
			while (s[j] && s[j] != d)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}

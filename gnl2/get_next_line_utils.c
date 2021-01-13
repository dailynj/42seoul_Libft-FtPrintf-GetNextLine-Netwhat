/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:12:51 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 16:34:23 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_nl_index(char *backup)
{
	ssize_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	ssize_t	i;

	if (!(s2 = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	ssize_t	i;
	ssize_t	j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (!(s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		s3[i] = s1[i];
	free(s1);
	j = -1;
	while (++j < ft_strlen(s2))
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

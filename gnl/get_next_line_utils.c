/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:10:11 by najlee            #+#    #+#             */
/*   Updated: 2021/01/12 22:38:03 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int	i;
	int	j;

	i = -1;
	if (!s1)
	{
		if (!(s3 = (char *)malloc(ft_strlen(s2) + 1)))
			return (NULL);
		while (*s2)
			(*s3)++ = (*s2)++;
		*s3 = '\0';
		return (s3);
	}
	if (!(s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
		(*s3)++ = (*s1)++;
	while (*s2)
		(*s3)++ = (*s2)++;
	free(s1);
	*s3 = '\0';
	return (s3);
}

int		ft_get_nl_index(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

char		*ft_substr(char *backup, int nl_index)
{
	char	*temp;
	int	len;
	int	i;

	len = ft_strlen(backup) - nl_index - 1;
	if (!((temp = (char *)malloc(len + 1))))
		return (NULL);
	i = nl_index + 1;
	while (backup[i])
	{
		*temp = backup[i];
		i++;
	}
	temp[i] = '\0';
	free(backup);
	return (temp);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

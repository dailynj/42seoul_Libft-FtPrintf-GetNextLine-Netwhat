/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:25:51 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 15:06:12 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nl_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n')
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*tmp;
	int	i;

	i = 0;
	if (!(tmp = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (i < ft_strlen(str))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int	i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!(tmp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
		tmp[i++] = *(s1++);
	while (*s2)
		tmp[i++] = *(s2++);
	tmp[i] = '\0';
	free(s1);
	return (tmp);
}

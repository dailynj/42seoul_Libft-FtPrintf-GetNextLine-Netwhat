/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:50:02 by najlee            #+#    #+#             */
/*   Updated: 2020/12/24 16:07:09 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (s1 && s2)
	{
		if (!(tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		while (*s1)
			tmp[i++] = *(s1++);
		while (*s2)
			tmp[i++] = *(s2++);
		tmp[i] = '\0';
	}
	else
		return (0);
	return (tmp);
}

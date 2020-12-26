/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:38:24 by najlee            #+#    #+#             */
/*   Updated: 2020/12/26 12:45:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	char **result;

	i = 0;
	j = 0;
	//malloc
	while (*s)
	{
		if (*s == c)
		{
			s++;
			while (*s == c)
				s++;
			i++;
			j = 0;
		}
		result[i][j++] = *(s++);
	}
	return (result);
}

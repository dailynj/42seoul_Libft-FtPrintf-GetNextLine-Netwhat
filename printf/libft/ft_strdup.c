/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:39:05 by najlee            #+#    #+#             */
/*   Updated: 2021/01/07 20:43:21 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*tmp;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	if (!(tmp = malloc(src_len + 1)))
		return (0);
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	free((char *)src);
	return (tmp);
}

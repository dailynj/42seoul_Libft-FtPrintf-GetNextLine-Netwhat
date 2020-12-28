/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:43:00 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/21 15:33:47 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	total;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	total = 0;
	while (dest[i] && i < size)
	{
		i++;
		total++;
	}
	while (dest[i])
		i++;
	while (src[j] && total < size - 1 && size)
	{
		dest[i++] = src[j++];
		total++;
	}
	while (src[j++])
		total++;
	dest[i] = '\0';
	return (total);
}

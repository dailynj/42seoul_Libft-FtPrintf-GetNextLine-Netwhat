/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:04:48 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 15:01:26 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (src[i] && i < dstsize - 1 && dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

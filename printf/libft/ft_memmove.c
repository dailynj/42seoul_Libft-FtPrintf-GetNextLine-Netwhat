/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:29:40 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 14:37:25 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest,
							const void *src, size_t len)
{
	unsigned int		i;
	unsigned char		*tmp;
	unsigned const char	*str;

	i = -1;
	tmp = dest;
	str = src;
	if (!dest && !src)
		return (0);
	if (dest < src)
		while (++i < len)
			tmp[i] = str[i];
	else
		while (++i < len)
			tmp[len - 1 - i] = str[len - 1 - i];
	return (dest);
}

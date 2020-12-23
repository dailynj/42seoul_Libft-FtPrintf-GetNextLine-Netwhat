/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:41:57 by najlee            #+#    #+#             */
/*   Updated: 2020/12/22 18:16:04 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dest,
								const void *src, unsigned int n)
{
	unsigned int			i;
	unsigned char			*tmp;
	unsigned const char		*str;

	i = -1;
	tmp = dest;
	str = src;
	if (!dest && !src)
		return (0);
	if (!n || dest == src)
		return (dest);
	while (++i < n)
		tmp[i] = str[i];
	return (dest);
}

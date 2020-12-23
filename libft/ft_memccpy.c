/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:47:09 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 14:36:38 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memccpy(void *dest,
		const void *src, int c, size_t n)
{
	unsigned char			*tmp;
	unsigned const char		*str;
	unsigned	int			i;

	i = 0;
	tmp = dest;
	str = src;
	if (!dest && !src)
		return (0);
	if (!n || dest == src)
		return (0);
	while (i < n)
	{
		tmp[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (0);
}

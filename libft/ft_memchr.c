/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:36:19 by najlee            #+#    #+#             */
/*   Updated: 2020/12/22 19:47:53 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(void *ptr, int value, unsigned int num)
{
	unsigned int	i;
	unsigned char	*str;

	i = -1;
	str = ptr;
	while (++i < num)
	{
		if (str[i] == (unsigned char)value)
			return (&ptr[i]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:37:08 by najlee            #+#    #+#             */
/*   Updated: 2020/12/27 12:55:06 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *str1,
								const void *str2, size_t n)
{
	unsigned const char	*tmp1;
	unsigned const char	*tmp2;
	unsigned int		i;

	i = 0;
	tmp1 = str1;
	tmp2 = str2;
	if (!n)
		return (0);
	while (tmp1[i] == tmp2[i] && i < (n - 1))
	{
		if (tmp1[i] != tmp2[i])
			return ((int)tmp1[i] - (int)tmp2[i]);
		i++;
	}
	if (tmp1[i] == tmp2[i])
		return (0);
	return ((int)tmp1[i] - (int)tmp2[i]);
}

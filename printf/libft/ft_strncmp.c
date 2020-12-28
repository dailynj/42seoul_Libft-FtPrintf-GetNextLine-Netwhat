/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:35:21 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 22:43:23 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
		i++;
	if (str1[i] == str2[i])
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:09:35 by suko              #+#    #+#             */
/*   Updated: 2020/12/26 19:34:42 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return (&((char *)s)[i - 1]);
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:13:43 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/21 15:40:42 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	ret;
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		if (hay[i] == needle[0])
		{
			ret = i;
			j = 0;
			while (needle[j] && hay[i + j] == needle[j] && i + j < len)
				j++;
			if (!needle[j])
				return (&(((char *)hay)[ret]));
		}
		i++;
	}
	return (NULL);
}

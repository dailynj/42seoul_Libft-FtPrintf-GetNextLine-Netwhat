/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:21:53 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 15:30:04 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)ft_calloc(len1 + len2 + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - len1];
		i++;
	}
	return (ptr);
}

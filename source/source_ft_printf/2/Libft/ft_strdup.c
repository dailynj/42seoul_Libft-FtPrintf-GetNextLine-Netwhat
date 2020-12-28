/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:30:23 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/21 15:18:47 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	if (!((ptr) = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:29:05 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 15:23:06 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s, const char *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	j;

	if (!s || !*s)
		return ((char *)s);
	if (!set)
		return ((char *)s);
	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (s[i] && ft_strchr(set, s[i]) && start <= i)
		i--;
	end = i;
	if (!(ptr = (char *)ft_calloc((end - start + 1) + 1, sizeof(char))))
		return (NULL);
	i = start;
	j = 0;
	while (i <= end)
		ptr[j++] = s[i++];
	return (ptr);
}

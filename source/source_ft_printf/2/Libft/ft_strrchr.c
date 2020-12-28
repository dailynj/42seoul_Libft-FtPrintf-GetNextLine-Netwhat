/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:03:39 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/21 11:12:40 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ret = i;
		i++;
	}
	if ((char)c == 0)
		return (&(((char *)s)[i]));
	else if (ret == 0 && s[0] != c)
		return (NULL);
	else
		return (&(((char *)s)[ret]));
}

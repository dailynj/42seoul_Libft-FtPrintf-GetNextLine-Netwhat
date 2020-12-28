/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:56:41 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 15:11:00 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*ptr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = -1;
	while ((++i) < len)
		ptr[i] = f(i, s[i]);
	return (ptr);
}

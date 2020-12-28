/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:07:06 by najlee            #+#    #+#             */
/*   Updated: 2020/12/27 19:18:19 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_handle_zero(void)
{
	char	*ptr;

	if (!(ptr = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	ptr[0] = '0';
	return (ptr);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	char	buf[20];
	int		tmp;
	int		len;

	if (n == 0)
		return (ft_handle_zero());
	tmp = n;
	len = 0;
	while (tmp)
	{
		buf[len] = (tmp % 10 > 0) ? (tmp % 10) + '0' : -(tmp % 10) + '0';
		tmp /= 10;
		len++;
	}
	if (n < 0)
		len++;
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	tmp = (n < 0) ? 0 : -1;
	ptr[0] = (n < 0) ? '-' : ptr[0];
	while ((++tmp) < len)
		ptr[tmp] = buf[len - 1 - tmp];
	return (ptr);
}

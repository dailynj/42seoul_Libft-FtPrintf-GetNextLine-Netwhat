/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_to_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:12 by najlee            #+#    #+#             */
/*   Updated: 2021/01/06 16:14:54 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char				*ft_handle_zero(void)
{
	char				*ptr;

	if (!(ptr = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	ptr[0] = '0';
	return (ptr);
}

char	*ft_make_u_to_d(unsigned int num)
{
	unsigned int	temp;
	int				len;
	char			*str;

	temp = num;
	if (temp == 0)
		return (ft_handle_zero());
	len = 0;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	if (!(str = (char *)ft_calloc(len + 1, 1)))
		return (NULL);
	while ((--len) >= 0)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

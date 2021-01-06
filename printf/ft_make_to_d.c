/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_to_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:12 by najlee            #+#    #+#             */
/*   Updated: 2021/01/06 18:37:30 by najlee           ###   ########.fr       */
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

char				*ft_make_u_to_d(unsigned int num)
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

int					ft_hexlen(unsigned int num)
{
	unsigned int	tmp;
	unsigned int	len;

	len = 0;
	tmp = num;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	return (len);
}

char				*ft_make_d_to_x(unsigned int num, char c)
{
	char			*p;
	char			*str;
	unsigned int	tmp;
	unsigned int	len;

	len = 0;
	p = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	tmp = num;
	if (tmp == 0)
		return (ft_handle_zero());
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	if (!(str = ft_calloc(len + 1, 1)))
		return (NULL);
	while(len--)
	{
		str[len] = p[num % 16];
		num /= 16;
	}
	return (str);
}

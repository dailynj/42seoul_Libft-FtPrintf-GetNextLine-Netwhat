/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utl_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:12:33 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 20:44:33 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static char	*ft_base(unsigned long long number, int base, int count, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + ('A' - 10);
		number /= base;
		count--;
	}
	return (str);
}

char		*ft_utoa_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	str = 0;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		count++;
	}
	if (!(str = malloc(count + 1)))
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}

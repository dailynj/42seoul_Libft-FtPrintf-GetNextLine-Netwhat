/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:07:06 by najlee            #+#    #+#             */
/*   Updated: 2020/12/26 16:53:23 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_getlen(int num)
{
	int			len;

	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char			*ft_printzero(void)
{
	char		*result;

	if (!(result = malloc(2)))
		return (0);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char			*ft_itoa(int n)
{
	char		*result;
	long long	num;
	int			len;

	num = n;
	len = ft_getlen(num);
	if (!(result = malloc(len + 1)))
		return (0);
	if (!n)
		return (ft_printzero());
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

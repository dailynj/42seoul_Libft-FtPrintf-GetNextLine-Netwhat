/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:11:31 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 20:47:31 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static int	ft_intlen(long n)
{
	size_t	length;
	int		neg;

	length = 0;
	neg = 0;
	if (n < 0)
	{
		length++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_generate(char *nc, long num, int length, int neg)
{
	if (num != 0)
		nc = malloc(sizeof(char) * (length + 1));
	else
		return (nc = ft_strdup("0"));
	if (!nc)
		return (0);
	neg = 0;
	if (num < 0)
	{
		neg++;
		num *= (-1);
	}
	nc[length] = '\0';
	while (--length)
	{
		nc[length] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		nc[0] = '-';
	else
		nc[0] = (num % 10) + '0';
	return (nc);
}

char		*ft_itoa_long(long n)
{
	int		length;
	char	*nc;
	long	num;
	int		neg;

	num = n;
	length = ft_intlen(num);
	nc = 0;
	neg = 0;
	if (!(nc = ft_generate(nc, num, length, neg)))
		return (0);
	return (nc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:37:39 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 14:39:38 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa(int n)
{
	char			rev[13];
	unsigned int	i;
	unsigned int	temp;
	char			*result;

	i = 0;
	temp = (n < 0) ? (unsigned int)n * (-1) : n;
	while (temp >= 1)
	{
		rev[i++] = temp % 10 + '0';
		temp = temp / 10;
	}
	result = malloc(sizeof(char) * ((n <= 0) ? i + 2 : i + 1));
	if (n < 0)
		rev[i++] = '-';
	else if (n == 0)
		rev[i++] = '0';
	temp = 0;
	while (result != 0 && i > 0)
		result[temp++] = rev[(i--) - 1];
	if (result != 0)
		result[temp] = '\0';
	return (result);
}

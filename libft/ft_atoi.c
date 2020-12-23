/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:44:03 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 23:00:26 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		ft_atoi(const char *str)
{
	int	minus;
	int	answer;
	int	i;

	i = 0;
	minus = 1;
	answer = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			answer = answer * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (minus * answer);
}

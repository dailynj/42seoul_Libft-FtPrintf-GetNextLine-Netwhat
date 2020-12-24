/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:37:21 by najlee            #+#    #+#             */
/*   Updated: 2020/12/24 20:44:15 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int end;
	int	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[i]))
		start = (i++) + 1;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		end = (i--);
	return (ft_substr(s1, start, end));
}

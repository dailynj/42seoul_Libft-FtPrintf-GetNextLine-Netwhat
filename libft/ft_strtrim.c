/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:37:21 by najlee            #+#    #+#             */
/*   Updated: 2020/12/24 19:01:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_inset(char c, char const *set)
{
	while (*set)
	{
		if (c == *(set++))
			return (1);
	}
	return (0);
}

char	*ft_result(char const *s1, int start, int end)
{
	char *tmp;

	if (!(tmp = malloc(end - start + 1)))
		return (0);
	while (start <= end)
		*tmp++ = s1[start++];
	*tmp = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int end;
	int	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	if (is_inset(s1[i], set))
		while (is_inset(s1[++i], set))
			start = i + 1;
	i = ft_strlen(s1) - 1;
	if (is_inset(s1[i], set))
		while (is_inset(s1[--i], set))
			end = i - 1;
	return (ft_result(s1, start, end));
}

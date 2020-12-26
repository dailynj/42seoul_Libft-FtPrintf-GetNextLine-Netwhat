/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:38:24 by najlee            #+#    #+#             */
/*   Updated: 2020/12/26 20:29:01 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_free(char **temp)
{
	size_t	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (0);
}

char		**ft_putresult(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (!k && s[k] != c)
			result[i][j++] = s[k];
		else if (k && s[k] == c && s[k - 1] != c)
		{
			result[i][j] = '\0';
			i++;
			j = 0;
		}
		else if (k && s[k] != c)
			result[i][j++] = s[k];
		k++;
	}
	if (j)
		result[i][j] = '\0';
	return (result);
}

char		**ft_j_malresult(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = -1;
	while (s[++k])
	{
		if (!k && s[k] != c)
			j++;
		else if (k && s[k] == c && s[k - 1] != c)
		{
			if (!(result[i] = (char *)malloc((sizeof(char)) * (j + 1))))
				return (ft_free(result));
			i++;
			j = 0;
		}
		else if (k && s[k] != c)
			j++;
	}
	if (j)
		if (!(result[i] = (char *)malloc((sizeof(char)) * (j + 1))))
			return (ft_free(result));
	return (result);
}

size_t		ft_get_i_num(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (!i && s[i] != c)
			num++;
		if (i && s[i] != c && s[i - 1] == c)
			num++;
		i++;
	}
	return (num);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i_num;

	if (!s)
		return (0);
	if (!c)
		return (0);
	i_num = ft_get_i_num(s, c);
	if (!(result = (char **)malloc((sizeof(char *)) * (i_num + 1))))
		return (0);
	result = ft_j_malresult(result, s, c);
	result[i_num] = 0;
	return (ft_putresult(result, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_to_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:12 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 20:56:26 by najlee           ###   ########.fr       */
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

char					*ft_make_u_to_d(unsigned int num)
{
	unsigned int		temp;
	int					len;
	char				*str;

	temp = num;
	if (temp == 0)
		return (str = ft_handle_zero());
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

char					*ft_make_d_to_x(unsigned int num, char c)
{
	char				*p;
	char				*str;
	unsigned int		tmp;
	unsigned int		len;

	len = 0;
	p = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	tmp = num;
	if (tmp == 0)
		return (str = ft_handle_zero());
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	if (!(str = ft_calloc(len + 1, 1)))
		return (NULL);
	while (len--)
	{
		str[len] = p[num % 16];
		num /= 16;
	}
	return (str);
}

char					*ft_make_d_to_p(unsigned long long num)
{
	char				*p;
	char				*str;
	unsigned long long	tmp;
	unsigned long long	len;

	len = 0;
	p = "0123456789abcdef";
	tmp = num;
	if (tmp == 0)
		return (str = ft_handle_zero());
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	if (!(str = ft_calloc(len + 1, 1)))
		return (NULL);
	while (len--)
	{
		str[len] = p[num % 16];
		num /= 16;
	}
	return (str);
}

char					*ft_di_main_str_none(int num,
								t_guide *guide, int nbrlen, char *str)
{
	char				*tmp;
	char				*str1;
	char				*str2;

	tmp = ft_strdup("-");
	if (num < 0 && guide->blank == '0' && guide->width > nbrlen
												&& guide->align == 'r')
	{
		str1 = ft_blank_str(guide->width - nbrlen - 1, guide->blank);
		str2 = ft_strcat(str1, str);
		str = ft_strcat(tmp, str2);
		ft_free_double(str1, str2);
	}
	else if (num < 0 && guide->blank == ' ' && guide->width > nbrlen
													&& guide->align == 'r')
	{
		str1 = ft_blank_str(guide->width - nbrlen - 1, guide->blank);
		str2 = ft_strcat(str1, tmp);
		str = ft_strcat(str2, str);
		ft_free_double(str1, str2);
	}
	else if (num < 0)
		str = ft_strcat(tmp, str);
	return (str);
}

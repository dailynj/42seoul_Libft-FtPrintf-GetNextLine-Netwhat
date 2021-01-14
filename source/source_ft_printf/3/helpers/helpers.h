/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:52:57 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 20:43:58 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

void	ft_putchar(char c);
int		ft_putchar_ret(char c);
int		ft_puts_precision(char *str, int precision);
char	*ft_utoa_base(unsigned long long number, int base);
char	*ft_str_tolower(char *str);
char	*ft_u_itoa(unsigned int n);

char	*ft_itoa_long(long n);

#endif

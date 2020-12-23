/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:16:11 by najlee            #+#    #+#             */
/*   Updated: 2020/12/23 01:00:17 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	*ft_memset(void *s, int c, unsigned int n);
void	ft_bzero(void *s, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
void	*ft_memmove(void *dest, const void *src, unsigned int len);
void	*ft_memchr(void *ptr, int value, unsigned int num);
int		ft_memcmp(const void *str1, const void *str2, unsigned int n);
unsigned int		ft_strlen(const char *str);

#endif

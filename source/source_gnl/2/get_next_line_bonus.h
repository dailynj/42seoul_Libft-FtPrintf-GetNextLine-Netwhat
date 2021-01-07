/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:56:07 by seujeon           #+#    #+#             */
/*   Updated: 2021/01/05 13:40:12 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 65536
# endif
# define NEXT 2
# define FLAG_EOF 0
# define FLAG_SUCCESS 1
# define FLAG_FAIL -1

typedef	struct	s_size
{
	ssize_t index;
	ssize_t len;
	int		ret;
}				t_size;

int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t len, size_t size);
size_t			ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strndup(char *str, size_t n);

#endif

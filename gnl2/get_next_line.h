/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:16 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 16:17:48 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 256

int		get_next_line(int fd, char **line);
void	ft_fill_line(char **backup, char **line, ssize_t nl_index);
int		ft_final(char **backup, char **line, ssize_t read_len);

ssize_t	ft_strlen(char *str);
ssize_t	ft_nl_index(char *backup);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif

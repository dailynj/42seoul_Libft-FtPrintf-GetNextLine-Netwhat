/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:23:56 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 15:05:57 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 256

int	get_next_line(int fd, char **line);
int	ft_final(char **backup, char **line, int read_len);
void	ft_fill_line(char **backup, char **line, int nl_line);
int	ft_strlen(char *str);
int	ft_nl_index(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif

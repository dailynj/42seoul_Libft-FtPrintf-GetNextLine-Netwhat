/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:58:25 by najlee            #+#    #+#             */
/*   Updated: 2021/01/12 22:33:30 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 256

int	get_next_line(int fd, char **line);

char	*ft_strjoin(char *s1, char *s2);
int	ft_get_nl_index(char *s);
char	*ft_substr(char *backup, int nl_index);
int	ft_strlen(char *s);

#endif

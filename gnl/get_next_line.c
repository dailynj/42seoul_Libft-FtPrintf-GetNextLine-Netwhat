/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:09:18 by najlee            #+#    #+#             */
/*   Updated: 2021/01/12 22:30:04 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static	char	*backup[OPEN_MAX];
	int		read_size;
	int		nl_index;

	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((nl_index = get_nl_index(backup[fd])) >= 0)
		{
			backup[fd] = fill_line(backp[fd], line, nl_index);
			return (1);
		}
	}
	return (last_process(&backup[fd], line, read_size));
}

char			*fill_line(char *backup, char **line, int nl_index)
{
	char		*tmp;
	int		i;

	if (!(*line = (char *)malloc(nl_index + 1)))
		return (NULL);
	i = -1;
	while (++i < nl_index)
		*line[i] = backup[i];
	*line[i] = '\0';
	tmp = ft_substr(backup, nl_index);
	free(backup);
	return (tmp);
}

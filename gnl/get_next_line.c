/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:22:54 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 15:12:51 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int		read_len;
	int		nl_index;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((nl_index = ft_nl_index(backup[fd])) >= 0)
		{
			ft_fill_line(&backup[fd], line, nl_line);
			return (1);
		}
	}
	return (ft_final(&backup[fd], line, read_len));
}

int			ft_final(char **backup, char **line, int read_len)
{
	if (read_len < 0)
		return (-1);
	if (*backup && (nl_index = ft_nl_index(*backup)) >= 0)
	{
		ft_fill_line(backup, line, nl_line);
		return (1);
	}
	else if (*backup)
	{
		*line = *backup;
		*backup = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

void			ft_fill_line(char **backup, char **line, int nl_line)
{
	int		i;

	if (!((*line) = (char *)malloc(nl_index + 1)))
		return (NULL);
	i = 0;
	while (i < nl_index)
	{
		(*line)[i] = (*backup)[i];
		i++;
	}
	(*line)[i] = '\0';
	if (!ft_strlen(&(*backup)[nl_index + 1]))
	{
		free(*backup);
		*backup = NULL;
		return ;
	}
	(*backup) = ft_strdup(&(*backup)[nl_index + 1]);
}

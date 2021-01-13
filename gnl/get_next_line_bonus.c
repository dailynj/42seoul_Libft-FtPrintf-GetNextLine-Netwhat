/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:57:16 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 20:33:46 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_nl_index(char *backup)
{
	ssize_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_fill_line(char **backup, char **line, ssize_t nl_index)
{
	char	*temp;
	ssize_t	i;

	if (!(*line = (char *)malloc(sizeof(char) * (nl_index + 1))))
		return ;
	i = 0;
	while (i < nl_index)
	{
		(*line)[i] = (*backup)[i];
		i++;
	}
	(*line)[i] = '\0';
	if (ft_strlen(&(*backup)[nl_index + 1]) == 0)
	{
		free(*backup);
		*backup = NULL;
		return ;
	}
	temp = ft_strdup(&(*backup)[nl_index + 1]);
	free(*backup);
	*backup = ft_strdup(temp);
	free(temp);
}

int		ft_final(char **backup, char **line, ssize_t read_len)
{
	ssize_t	nl_index;

	if (read_len < 0)
		return (-1);
	if (*backup && (nl_index = ft_nl_index(*backup)) >= 0)
	{
		ft_fill_line(backup, line, nl_index);
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

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	ssize_t		read_len;
	ssize_t		nl_index;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((nl_index = ft_nl_index(backup[fd])) >= 0)
		{
			ft_fill_line(&backup[fd], line, nl_index);
			return (1);
		}
	}
	return (ft_final(&backup[fd], line, read_len));
}

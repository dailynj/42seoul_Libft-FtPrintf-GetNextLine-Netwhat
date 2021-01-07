/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:03:11 by jaehpark          #+#    #+#             */
/*   Updated: 2020/12/30 02:05:14 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	strline(char *storage)
{
	ssize_t	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	separate(char **storage, char **line, ssize_t cut)
{
	char	*temp;
	ssize_t	i;

	if (!(*line = (char *)malloc(sizeof(char) * (cut + 1))))
		return ;
	i = 0;
	while (i < cut)
	{
		(*line)[i] = (*storage)[i];
		i++;
	}
	(*line)[i] = '\0';
	if (ft_strlen(&(*storage)[cut + 1]) == 0)
	{
		free(*storage);
		*storage = NULL;
		return ;
	}
	temp = ft_strdup(&(*storage)[cut + 1]);
	free(*storage);
	*storage = ft_strdup(temp);
	free(temp);
}

int		last_process(char **storage, char **line, ssize_t read_size)
{
	ssize_t	cut;

	if (read_size < 0)
		return (-1);
	if (*storage && (cut = strline(*storage)) >= 0)
	{
		separate(storage, line, cut);
		return (1);
	}
	else if (*storage)
	{
		*line = *storage;
		*storage = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*storage[OPEN_MAX];
	ssize_t		read_size;
	ssize_t		cut;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buf);
		if ((cut = strline(storage[fd])) >= 0)
		{
			separate(&storage[fd], line, cut);
			return (1);
		}
	}
	return (last_process(&storage[fd], line, read_size));
}

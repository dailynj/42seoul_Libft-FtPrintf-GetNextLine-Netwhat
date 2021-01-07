/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:59:31 by seujeon           #+#    #+#             */
/*   Updated: 2021/01/05 13:39:40 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	check_newline(char *str)
{
	char *start;

	start = str;
	while (str - start < BUFFER_SIZE && *str)
	{
		if (*str == '\n')
			return (str - start);
		++str;
	}
	return (-1);
}

static int		ft_split_and_set(int fd, char **line, char *fd_buf[], int index)
{
	char	*pre_buf;
	char	*head;
	char	*tail;

	pre_buf = fd_buf[fd];
	if ((head = ft_strndup(pre_buf, index)) == NULL)
		return (0);
	if ((tail = ft_strndup(pre_buf + index + 1,
						ft_strlen(pre_buf) - index - 1)) == NULL)
		return (0);
	fd_buf[fd] = tail;
	*line = head;
	free(pre_buf);
	return (FLAG_SUCCESS);
}

static int		ft_process(char **fd_buf, char **line, char *buf, t_size size)
{
	if (size.len < 0)
	{
		free(buf);
		return (FLAG_FAIL);
	}
	if ((size.index = check_newline(buf)) >= 0)
	{
		if ((*line = ft_strjoin(*line, ft_strndup(buf, size.index))) == NULL)
		{
			free(buf);
			return (FLAG_FAIL);
		}
		*fd_buf = ft_strndup(buf + size.index + 1, size.len - size.index - 1);
		free(buf);
		return (FLAG_SUCCESS);
	}
	*line = ft_strjoin(*line, ft_strndup(buf, size.len));
	*fd_buf = *line;
	if (size.len < BUFFER_SIZE)
	{
		*fd_buf = NULL;
		free(buf);
		return (FLAG_EOF);
	}
	return (NEXT);
}

static int		ft_process_eof(char *buf, char **line, char **fd_buf)
{
	free(buf);
	if (*line != NULL)
		*fd_buf = NULL;
	else
	{
		if ((*line = ft_strndup("", 0)) == NULL)
			return (FLAG_FAIL);
		*fd_buf = NULL;
	}
	return (FLAG_EOF);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*fd_buf[OPEN_MAX];
	t_size		size;

	if (fd < 0 || fd >= OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = fd_buf[fd];
	if (*line != NULL && ((size.index = check_newline(*line)) >= 0))
	{
		if (ft_split_and_set(fd, line, fd_buf, size.index))
			return (FLAG_SUCCESS);
		else
			return (FLAG_FAIL);
	}
	if ((buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))) == NULL)
		return (FLAG_FAIL);
	while ((size.len = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (size.len > 0)
			*(buf + size.len) = '\0';
		if ((size.ret = ft_process(&fd_buf[fd], line, buf, size)) != NEXT)
			return (size.ret);
	}
	return (ft_process_eof(buf, line, &fd_buf[fd]));
}

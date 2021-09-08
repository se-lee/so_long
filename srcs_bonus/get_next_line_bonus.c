/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:41:39 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:09 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	clean_free(void **data)
{
	free(*data);
	*data = NULL;
}

void	var_init(char **store, int	*size_read, char **new_line)
{
	if (!*store)
		*store = ft_strdup("");
	*size_read = 1;
	*new_line = ft_strchr(*store, '\n');
}

void	append_string(char **str_pointer, const char *to_append)
{
	char	*str;

	str = *str_pointer;
	*str_pointer = ft_strjoin(str, to_append);
	free(str);
}

int	return_result(char *new_line, char **store, char **line)
{
	char	*temp;

	if (new_line)
	{
		*new_line = '\0';
		*line = ft_strdup(*store);
		temp = ft_strdup(new_line + 1);
		if (*store)
			free(*store);
		*store = temp;
		return (1);
	}
	*line = ft_strdup(*store);
	clean_free((void **)store);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*new_line;
	char		buf[BUFFER_SIZE + 1];
	static char	*stores[OPEN_MAX] = {NULL};
	int			size_read;

	if ((fd < 0) || (fd >= OPEN_MAX) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	var_init(&stores[fd], &size_read, &new_line);
	while (size_read > 0 && !new_line)
	{
		size_read = 0;
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read < 0)
		{
			clean_free((void **)&stores[fd]);
			return (-1);
		}
		buf[size_read] = '\0';
		append_string(&stores[fd], buf);
		new_line = ft_strchr(stores[fd], '\n');
	}
	return (return_result(new_line, &stores[fd], line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:48:25 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 18:16:27 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_count_row_column(t_var_set *var, int fd)
{
	int		column_count;
	char	buf;

	column_count = 0;
	var->map.column_count = 0;
	var->map.row_count = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			var->map.row_count++;
			if (var->map.column_count < column_count)
				var->map.column_count = column_count;
			column_count = 0;
		}
		else
			column_count++;
	}
}

void	map_malloc(t_var_set *var, int fd)
{
	int		i;

	i = 0;
	var->map.array = NULL;
	map_count_row_column(var, fd);
	var->map.array = (char **)malloc(sizeof(char *)
			* var->map.row_count);
	while (i < var->map.row_count)
	{
		var->map.array[i] = (char *)malloc(sizeof(char)
				* var->map.column_count);
		i++;
	}
}

void	map_read_file(t_var_set *var, char *map_file)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			var->map.array[i][j] = line[j];
			map_count_compo(var, line[j]);
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	map_read_and_check(t_var_set *var, char *map_path)
{
	int		fd;

	map_check_file_extension(map_path, ".ber");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_message_exit("File open failed");
	init_map_value(var);
	map_malloc(var, fd);
	close(fd);
	map_read_file(var, map_path);
	player_get_coord(var);
	map_check_format(var);
}

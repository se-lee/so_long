/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:48:25 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 00:32:29 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_count_row_column(t_var_set *var, int fd)
{
	int		temp;
	char	buf;

	temp = 0;
	var->map.column_count = 0;
	var->map.row_count = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (var->map.column_count < temp)
			var->map.column_count = temp;
		if (buf == '\n')
		{
			var->map.row_count++;
			temp = 0;
		}
		else
			temp++;
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
	if (fd < 0)
		error_message_exit("Error: File open failed");
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

	fd = open(map_path, O_RDONLY);
	init_map_value(var);
printf("p1: %d\n", var->map.p_count);
	map_malloc(var, fd);
	close(fd);
	map_read_file(var, map_path);
	map_get_player_coord(var);
	map_check_format(var);
	close(fd);
}

	// int	i = 0;
	// while (i < var->map.row_count)
	// {
	// int	j = 0;
	// 	printf("arr[%d]:", i);
	// 	while (j < var->map.column_count)
	// 	{
	// 		printf("%c", var->map.array[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
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
		if (var->map.column_count < temp) //max column count
			var->map.column_count = temp;
		if (buf == '\n')
		{
			temp = 0;
			var->map.row_count++;
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
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			// if (map_compo_is_correct(line[j]))
				var->map.array[i][j] = line[j];
			// else
			// 	ft_putendl_fd("Error: Invalid composition", 2);
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void		map_read_and_check(t_var_set *var, char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	map_malloc(var, fd);
	close(fd);
	map_read_file(var, map_path);
	if (!map_format_is_correct(var))
		exit(0);
// if !map format is correct, error and exit
	map_get_player_coord(var);
	int	i = 0;
	while (i < var->map.row_count) //var->map.array[i])
	{
	int	j = 0;
		printf("arr[%d]:", i);
		while (j < var->map.column_count)
		{
			printf("%c", var->map.array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	close(fd);
}

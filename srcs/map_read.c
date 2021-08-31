#include "../include/so_long.h"

// get size of map - count rows and columns

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
debug(printf, "row: %d, column: %d\n", var->map.row_count, var->map.column_count);
	var->map.array = (char **)malloc(sizeof(char *) * var->map.row_count + 1);
	while (i < var->map.row_count)
	{
		var->map.array[i] = (char *)malloc(sizeof(char) * var->map.column_count + 1);
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
		while (j < var->map.column_count + 1)
		{
			var->map.array[i][j] = line[j];
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

	// path = "./map/map.ber";
	fd = open(map_path, O_RDONLY);
	map_malloc(var, fd);
	close(fd);
	map_read_file(var, map_path);
	map_format_is_correct(var);
//	map_compo_count_get_coord(var);

	int	i = 0;
	while (var->map.array[i])
	{
		printf("arr[%d]: %s\n", i, var->map.array[i]);
		i++;
	}
	close(fd);
}

/*
when the program is executed, it runs without any problem
but when i execute repeatedly, sometimes it gets segfault
did i malloc wrong? malloc or gnl?
*/
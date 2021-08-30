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
	var->map.array = (char **)malloc(sizeof(char *) * var->map.row_count);
	while (i < var->map.row_count)
	{
		var->map.array[i] = (char *)malloc(sizeof(char) * var->map.column_count + 1);
		i++;
	}
}

void	map_read_file(t_var_set *var, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
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
}

int		map_read_and_check(t_var_set *var)
{
	int		fd;

	fd = open("path", O_RDONLY);
	map_count_row_column(var, fd);
	map_malloc(var, fd);
	map_read_file(var, fd);
	map_check();

	close(fd);
}


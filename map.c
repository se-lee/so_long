#include "include/so_long.h"

void	map_count_row(int fd, t_map *map)
{
	char	*line;

	map->row = 0;
	map->column = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map->row++;
		map->column = ft_strlen(line);
		free(line);
	}
	map->row++;
}

/* check malloc -- make sure where mallocs are used in gnl funct. */
/* i feel i'm mallocing too much */

void	map_malloc(int fd, t_map *map)
{
	char	**map_arr;
	int		i;

	i = 0;
	map_arr = (char **)malloc(sizeof(char *) * map->row);
	while (i < map->row)
	{
		map_arr[i] = (char *)malloc(sizeof(char) * map->column);
		i++;
	}
}

int		map_read(char *map_filename, t_map *map)
{
	int	fd;
	fd = open(map_filename, O_RDONLY);
	map_count_row(fd, map);
	return (1);
}

int main()
{
	t_map map;

	map_read("map.ber", &map);
	printf("row: %d\n", map.row);
	printf("column: %d\n", map.column);
	return (0);
}

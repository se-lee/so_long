#include "include/so_long.h"

void	map_count_row_and_column(int fd, t_map *map)
{
//	char	*line;
	char	buff;
	int		temp;

	map->row = 0;
	map->column = 0;
	temp = 0;
	while (read(fd, &buff, 1) > 0)
	{
		if (map->column < temp)
			map->column = temp;
		if (buff == '\n')
		{
			map->row++;
			temp = 0;
		}
		else
			temp++;
	}
/* i feel i'm malloc-ing too much */
	// while (get_next_line(fd, &line) > 0)
	// {
	// 	map->row++;
	// 	map->column = ft_strlen(line);
	// 	free(line);
	// }
	// map->row++;
}
/* check malloc -- make sure where mallocs are used in gnl funct. */
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
	map_count_row_and_column(fd, map);
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

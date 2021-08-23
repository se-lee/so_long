#include "include/so_long.h"

void	map_count_row(int fd, t_map *map)
{
	char	*line;

	map->row = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map->row++;
		free(line);
	}
}

// void	map_count_column()
// {
// }

// void	map_malloc(int fd, t_map *map)
// {
// 	char	**map;
// // malloc with the length of each row (length == number of column)
// // malloc rows (repeat ueno malloc upto the number of rows)
// }

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
	return (0);
}

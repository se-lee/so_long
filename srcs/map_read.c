#include "../include/so_long.h"

void	map_count_row_and_column(int fd, t_map *map)
{
	char	buff;
	int		temp;

	map->row_count = 0;
	map->column_count = 0;
	temp = 0;
	while (read(fd, &buff, 1) > 0)
	{
		if (map->column_count < temp)
			map->column_count = temp;
		if (buff == '\n')
		{
			map->row_count++;
			temp = 0;
		}
		else
			temp++;
	}
}

void	map_malloc(int fd, t_map *map)
{
	int		i;

	i = 0;
	map_count_row_and_column(fd, map);
	map->map_arr = (char **)malloc(sizeof(char *) * map->row_count + 1);
	while (i < map->row_count)
	{
		map->map_arr[i] = (char *)malloc(sizeof(char) * map->column_count);
		i++;
	}
}

void		map_read(char *map_filename, t_map *map)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(map_filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (j < map->column_count + 1)
		{
			map->map_arr[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

/*
int main()
{
	t_map map;
	int		i;
	int		fd;

	i = 0;
	fd = open("map_ber/map.ber", O_RDONLY);
	map_malloc(fd, &map);
	close(fd);
	map_read("map_ber/map.ber", &map);
	printf("row: %d\n", map.row_count);
	printf("column: %d\n", map.column_count);
	// if (!map_format_is_correct(&map))
	// 	return (0);
	while (i < map.row_count)
	{
		printf("map[%d]: %s \n", i, map.map_arr[i]);
		i++;
	}
	return (0);
}
*/

/*
open / close を　Map_readにふくめてやるとうまく読み込めない。
マップマロックを外に出して分けて実行したらうまくいった
なんでだ？
*/

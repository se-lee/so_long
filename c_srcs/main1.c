#include "../include/so_long.h"

int main()
{
	t_id id;
	t_map		map;
	t_tile		tile;
	int			fd;
	int			i;
	// int			j;
	char		*path;

	path = "./map_ber/map.ber";
	id.mlx = mlx_init();
	fd = open(path, O_RDONLY);
	map_malloc(fd, &map);
	close(fd);
	map_read(path, &map);
	id.win = mlx_new_window(id.mlx, TILE_SIZE * map.column_count, TILE_SIZE * map.row_count, "so_long");
	i = 0;
	while (map.array[i])
	{
		printf("map[%i]:%p : %s\n", i, map.array[i], map.array[i]);
		i++;
	}
	map_draw_wall_and_background(&id, &map, &tile);
	free_map_arr(&map);
	exit_game(&id);
	mlx_loop(id.mlx);
	
	return (0);
}

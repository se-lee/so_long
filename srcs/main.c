#include "../include/so_long.h"

int main()
{
	t_identifier id;
//	t_image		img;
	t_map		map;
	t_tile		tile;
	int			fd;

	id.mlx = mlx_init();
	fd = open("map_ber/map.ber", O_RDONLY);
	map_malloc(fd, &map);
	close(fd);
	map_read("map_ber/map.ber", &map);
	id.win = mlx_new_window(id.mlx, TILE_SIZE * map.column_count, TILE_SIZE * map.row_count, "so_long");
	map_draw_wall_and_background(&id, &map, &tile);
printf("row: %d  column: %d  \n", map.row_count, map.column_count);

	mlx_key_hook(id.win, exit_with_esc_key, &id);

//	exit_game(&id);
	mlx_loop(id.mlx);
	return (0);
}

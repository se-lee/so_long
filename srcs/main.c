#include "../include/so_long.h"

int main()
{
	t_identifier id;
	t_image		img;
	t_map		map;
	t_tile		tile;
	int			fd;

	id.mlx = mlx_init();
	fd = open("map_ber/map.ber", O_RDONLY);
	map_malloc(fd, &map);
	close(fd);
	map_read("map_ber/map.ber", &map);
	id.win = mlx_new_window(id.mlx, TILE_SIZE * map.row_count, TILE_SIZE * map.column_count, "so_long");
	map_draw_background(&id, &img, &map, &tile);
	mlx_loop(id.mlx);
	exit_game(&id);
	
	return (0);
}

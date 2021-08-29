#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"
#include "../assets_xpm/test_yellow32.xpm"

int	main()
{
	t_id	id;
	t_map	map;
	t_tile	tile;
	t_player	player;
	int		i;
	int		j;
	int		fd;
	char	*path_map;
	char	*path_wall;
	char	*path_space;
	char 	*path_exit;
	char	*path_player;

	path_map = "./map_ber/map.ber";
	path_wall = "./assets_xpm/test_yellow32.xpm";
	path_space = "./assets_xpm/test_green32.xpm";
	path_exit = "./assets_xpm/test_stripe32.xpm";
	path_player = "./assets_xpm/test_red32.xpm";

	fd = open(path_map, O_RDONLY);
	map_malloc(fd, &map);
	close(fd);	
	map_read(path_map, &map);
	id.mlx = mlx_init();
	id.win = mlx_new_window(id.mlx, TILE_SIZE * map.column_count, TILE_SIZE * map.row_count, "ちゅーじん好き♡");
	tile.space.img_ptr = mlx_xpm_file_to_image(id.mlx, path_space, &tile.space.width, &tile.space.height);
	tile.space.addr = mlx_get_data_addr(tile.space.img_ptr, &tile.space.bits_per_pixel, &tile.space.line_length, &tile.space.endian);
	tile.wall.img_ptr = mlx_xpm_file_to_image(id.mlx, path_wall, &tile.wall.width, &tile.wall.height);
	tile.wall.addr = mlx_get_data_addr(tile.wall.img_ptr, &tile.wall.bits_per_pixel, &tile.wall.line_length, &tile.wall.endian);
	tile.exit.img_ptr = mlx_xpm_file_to_image(id.mlx, path_exit, &tile.exit.width, &tile.exit.height);
	tile.exit.addr = mlx_get_data_addr(tile.exit.img_ptr, &tile.exit.bits_per_pixel, &tile.exit.line_length, &tile.exit.endian);

	player.image.img_ptr = mlx_xpm_file_to_image(id.mlx, path_player, &player.image.width, &player.image.height);
	player.image.addr = mlx_get_data_addr(player.image.img_ptr, &player.image.bits_per_pixel, &player.image.line_length, &player.image.endian);

	printf("tile w: %d h: %d\n", tile.space.width, tile.space.height);

	i = 0;
	while (i < map.row_count)
	{
		j = 0;
		while (j < map.column_count)
		{
			if (map.map_arr[i][j] == '1')
				mlx_put_image_to_window(id.mlx, id.win, tile.wall.img_ptr, (j * TILE_SIZE) , (i * TILE_SIZE));
			else if (map.map_arr[i][j] == 'E')
				mlx_put_image_to_window(id.mlx, id.win, tile.exit.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
			else if (map.map_arr[i][j] == 'P')
			{
				mlx_put_image_to_window(id.mlx, id.win, player.image.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
				map_get_player_coordinate(&map, &player);
			}
			else
				mlx_put_image_to_window(id.mlx, id.win, tile.space.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
			j++;
		}
		i++;
	}
	printf("player: x:%d  y: %d\n", player.coordi.x, player.coordi.y);
	move_player(&id);
	printf("player: x:%d  y: %d\n", player.coordi.x, player.coordi.y);
	exit_game(&id);
	mlx_loop(id.mlx);
}

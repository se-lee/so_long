#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"
#include "../assets_xpm/test_yellow32.xpm"

int	main()
{
	t_id	id;
	t_map	map;
	t_tile	tile;
	int		i;
	int		j;
	int		fd;
	char	*path_map;
	char	*path_wall;
	char	*path_space;

	path_map = "./map_ber/map.ber";
	path_wall = "./assets_xpm/test_yellow32.xpm";
	path_space = "./assets_xpm/test_green32.xpm";

	fd = open(path_map, O_RDONLY);
	map_malloc(fd, &map);
	close(fd);	
	map_read(path_map, &map);
	id.mlx = mlx_init();
	id.win = mlx_new_window(id.mlx, TILE_SIZE * map.column_count, TILE_SIZE * map.row_count, "PLEEEEZZZ");
	tile.space.img_ptr = mlx_xpm_file_to_image(id.mlx, path_space, &tile.space.width, &tile.space.height);
	tile.space.addr = mlx_get_data_addr(tile.space.img_ptr, &tile.space.bits_per_pixel, &tile.space.line_length, &tile.space.endian);
	tile.wall.img_ptr = mlx_xpm_file_to_image(id.mlx, path_wall, &tile.wall.width, &tile.wall.height);
	tile.wall.addr = mlx_get_data_addr(tile.wall.img_ptr, &tile.wall.bits_per_pixel, &tile.wall.line_length, &tile.wall.endian);
	printf("tile w: %d h: %d\n", tile.space.width, tile.space.height);

	i = 0;
	while (i < map.row_count)
	{
		j = 0;
		while (j < map.column_count)
		{
			if (map.map_arr[i][j] == '1')
				mlx_put_image_to_window(id.mlx, id.win, tile.wall.img_ptr, (j * TILE_SIZE) , (i * TILE_SIZE));
			else
				mlx_put_image_to_window(id.mlx, id.win, tile.space.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
			j++;
		}
		i++;
	}
	exit_game(&id);
	mlx_loop(id.mlx);

}


// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }
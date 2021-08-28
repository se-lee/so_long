#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"
#include "../assets_xpm/test_yellow32.xpm"

void	map_draw_wall_and_background(t_id *id, t_map *map, t_tile *tile)
{
	int	i;
	int	j;
	char	*wall_path = "../assets_xpm/test_yellow32.xpm";
	char	*space_path = "../assets_xpm/test_green32.xpm";

	tile->space.img_ptr = mlx_xpm_file_to_image(id->mlx, space_path,
					&tile->space.width, &tile->space.height);
	tile->wall.img_ptr = mlx_xpm_file_to_image(id->mlx, wall_path,
					&tile->wall.width, &tile->wall.height);
	tile->space.addr = mlx_get_data_addr(tile->space.img_ptr, &tile->space.bits_per_pixel,
					&tile->space.line_length, &tile->space.endian);
	tile->wall.addr = mlx_get_data_addr(tile->wall.img_ptr, &tile->wall.bits_per_pixel,
					&tile->wall.line_length, &tile->wall.endian);
	printf("img_ptr:s: %p  \n", tile->space.addr);

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			// if (map->map_arr[i][j] == '1')
			// 	mlx_put_image_to_window(id->mlx, id->win, tile->wall.img_ptr,
			// 		(j * TILE_SIZE), (i * TILE_SIZE));
			// else
				mlx_put_image_to_window(id->mlx, id->win, tile->space.img_ptr,
					(j * TILE_SIZE), (i * TILE_SIZE));
			j++;
		}
		i++;
	}
}

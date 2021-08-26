#include "../include/so_long.h"

void	map_draw_wall_and_background(t_identifier *id, t_map *map, t_tile *tile)
{
	int	i;
	int	j;

	tile->background.img_ptr = mlx_xpm_file_to_image(id->mlx, "./assets_xpm/test_green32.xpm", &tile->tile_width, &tile->tile_height);
	tile->wall.img_ptr = mlx_xpm_file_to_image(id->mlx, "./assets_xpm/test_yellow32.xpm", &tile->tile_width, &tile->tile_height);
	tile->exit.img_ptr = mlx_xpm_file_to_image(id->mlx, "./assets_xpm/test_stripe32.xpm", &tile->tile_width, &tile->tile_height);

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			if (map->map_arr[i][j] == '1')
				mlx_put_image_to_window(id->mlx, id->win, tile->wall.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			else if (map->map_arr[i][j] == 'E')
				mlx_put_image_to_window(id->mlx, id->win, tile->exit.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			else 
				mlx_put_image_to_window(id->mlx, id->win, tile->background.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

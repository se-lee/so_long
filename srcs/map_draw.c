#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"
#include "../assets_xpm/test_yellow32.xpm"


/*void	map_draw_wall_and_background(t_identifier *id, t_map *map, t_tile *tile)
{
	int	i;
	int	j;

	tile->background.img_ptr = mlx_xpm_file_to_image(id->mlx, "assets_xpm/test_green32.xpm", &tile->tile_width, &tile->tile_height);
	tile->wall.img_ptr = mlx_xpm_file_to_image(id->mlx, "assets_xpm/test_yellow32.xpm", &tile->tile_width, &tile->tile_height);
//	tile->exit.img_ptr = mlx_xpm_file_to_image(id->mlx, "assets_xpm/test_stripe32.xpm", &tile->tile_width, &tile->tile_height);

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			// if (map->map_arr[i][j] == '1')
			// 	mlx_put_image_to_window(id->mlx, id->win, tile->wall.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			// // else if (map->map_arr[i][j] == 'E')
			// // 	mlx_put_image_to_window(id->mlx, id->win, tile->exit.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			// else 
			mlx_put_image_to_window(id->mlx, id->win, tile->background.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
*/

void	map_draw_background(t_identifier *id, t_map *map, t_tile *tile)
{
	int		i;
	int		j;
// put file path into header? or make it as a variable 
	tile->background.img_ptr = mlx_xpm_file_to_image(id->mlx, "../assets_xpm/test_green32.xpm", &tile->tile_width, &tile->tile_height);
//	tile->background.addr = mlx_get_data_addr(tile->background.img_ptr, &tile->background.bits_per_pixel, &tile->background.line_length, &tile->background.endian);

	i = 0;
	while (i < (TILE_SIZE * map->row_count))
	{
		j = 0;
		while (j < (TILE_SIZE * map->column_count))
		{
			mlx_put_image_to_window(id->mlx, id->win, tile->background.img_ptr, j, i);
			j = j + TILE_SIZE;
		}
		i = i + TILE_SIZE;
	}
}

void	map_draw_wall_and_background(t_identifier *id, t_map *map, t_tile *tile)
{
	int	i;
	int	j;
	char *path;

	path = "../assets_xpm/test_green32.xpm";
	tile->background.img_ptr = mlx_xpm_file_to_image(id->mlx, path, &tile->background.width, &tile->background.height);
	tile->wall.img_ptr = mlx_xpm_file_to_image(id->mlx, "../assets_xpm/test_yellow32.xpm", &tile->wall.width, &tile->wall.height);
	tile->background.addr = mlx_get_data_addr(tile->background.img_ptr, &tile->background.bits_per_pixel, &tile->background.line_length, &tile->background.endian);
	tile->wall.addr = mlx_get_data_addr(tile->wall.img_ptr, &tile->wall.bits_per_pixel, &tile->wall.line_length, &tile->wall.endian);

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			if (map->map_arr[i][j] == '1')
				mlx_put_image_to_window(id->mlx, id->win, tile->wall.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
			else
				mlx_put_image_to_window(id->mlx, id->win, tile->background.img_ptr, (j * TILE_SIZE), (i * TILE_SIZE));
			j++;
		}
		i++;
	}
}

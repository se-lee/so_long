#include "../include/so_long.h"

// parsing functions

/*
if 1 
else if 0 
else if p
else if e
else if c
else error

! need to know the coordinates (where to put what)
*/

/*
void	map_put_tile
	(t_identifier *id, t_image *img, t_map *map, int x, int y)
{
	mlx_put_image_to_window(id->mlx, id->win, img->img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}
*/

void	map_draw_background(t_identifier *id, t_image *img, t_map *map, t_tile *tile)
{
	int		i;
	int		j;

	img->img_ptr = mlx_xpm_file_to_image(id->mlx, "./assets_xpm/test_green32.xpm", &tile->tile_width, &tile->tile_height);

	i = 0;
	while (i < (TILE_SIZE * map->row_count))
	{
		j = 0;
		while (j < (TILE_SIZE * map->column_count))
		{
			mlx_put_image_to_window(id->mlx, id->win, img->img_ptr, j, i);
			j = j + TILE_SIZE;
		}
		i = i + TILE_SIZE;
	}
}

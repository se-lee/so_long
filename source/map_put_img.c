#include "include/so_long.h"

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

void	map_put_tile
	(t_identifier *id, t_image *img, t_map *map, int x, int y)
{
	mlx_put_image_to_window(id->mlx, id->win, img->img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}


#include "include/so_long.h"

// parsing functions

/*
if 1 
else if 0 
else if p
else if e
else if c
else error

need to find the coordinates (where to put what)

*/

void	map_put_tile
	(t_identifier *id, t_image *img, t_map *map, int x, int y)
{
	draw_32(id, img, x * map->column_count, y * map->row_count);
}





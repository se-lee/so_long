#include "../include/so_long.h"

void		draw_32(t_identifier *id, t_image *img, int x, int y)
{
	mlx_put_image_to_window(id->mlx, id->win, img->img_ptr, * TILE_SIZE, y * TILE_SIZE);
}


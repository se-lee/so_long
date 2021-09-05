#include "../include/so_long.h"


/*

*/

int	collect_put_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->collec.image.ptr, var->collec.x * TILE_SIZE,
		var->collec.y * TILE_SIZE);
	return (0);
}



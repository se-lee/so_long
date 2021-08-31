#include "../include/so_long.h"

void	player_put_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->player.image.ptr, var->player.coord.x * TILE_SIZE,
		var->player.coord.y * TILE_SIZE);
}


/*

** Synchronize frames of all windows in MLX.
**
** @param	void *mlx_ptr	the mlx instance;
** @return	int				has no return value (bc).

int		mlx_do_sync(void *mlx_ptr);

*/
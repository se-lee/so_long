#include "../include/so_long.h"

int	player_put_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->player.image.ptr, var->player.x * TILE_SIZE,
		var->player.y * TILE_SIZE);
	return (0);
}

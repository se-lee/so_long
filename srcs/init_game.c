#include "../include/so_long.h"

void	init_mlx_and_win(t_var_set *var)
{
	int	size_x;
	int	size_y;

	size_x = var->map.column_count * TILE_SIZE;
	size_y = var->map.row_count * TILE_SIZE;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, size_x, size_y, "so_long");
}

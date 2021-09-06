#include "../include/so_long.h"

/* reduce lines:
 - put player and collec in a separate function
*/

void	map_put_to_win(t_var_set *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.row_count)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			if (var->map.array[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->win,
					var->tile.wall.ptr, j * TILE_SIZE, i * TILE_SIZE);
			else if (var->map.array[i][j] == '0' || var->map.array[i][j] == 'P'
					|| var->map.array[i][j] == 'C')
				mlx_put_image_to_window(var->mlx, var->win,
					var->tile.space.ptr, j * TILE_SIZE, i * TILE_SIZE);
			else if (var->map.array[i][j] == 'E')
				mlx_put_image_to_window(var->mlx, var->win,
					var->tile.exit.ptr, j * TILE_SIZE, i * TILE_SIZE);
			if (var->map.array[i][j] == 'C')
				mlx_put_image_to_window(var->mlx, var->win, 
					var->collec.image.ptr, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}


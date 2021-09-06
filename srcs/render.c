/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:50:02 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 19:04:14 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_put_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->player.image.ptr, var->player.x * TILE_SIZE,
		var->player.y * TILE_SIZE);
}

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
			mlx_put_image_to_window(var->mlx, var->win,
				var->tile.space.ptr, j * TILE_SIZE, i * TILE_SIZE);
			if (var->map.array[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->win,
					var->tile.wall.ptr, j * TILE_SIZE, i * TILE_SIZE);
			if (var->map.array[i][j] == 'E')
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

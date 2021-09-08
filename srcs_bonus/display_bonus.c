/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:50:02 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:46:58 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	put_player_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->player.image.ptr, var->player.x * TILE_SIZE,
		var->player.y * TILE_SIZE);
}

void	put_map_to_win(t_var_set *var)
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

void	put_start_messsage(t_var_set *var)
{
	int	x;
	int	y;

	x = (var->map.column_count / 3) * TILE_SIZE;
	y = (var->map.row_count / 2) * TILE_SIZE;
	mlx_string_put(var->mlx, var->win, x, y, 0xFFFFFF, "PRESS SPACE TO START");
}

void	put_continue_messsage(t_var_set *var)
{
	int	x;
	int	y;

	x = (var->map.column_count / 3) * TILE_SIZE;
	y = (var->map.row_count / 2) * TILE_SIZE;
	mlx_string_put(var->mlx, var->win, x, y, 0x000000,
		"COLLECT ALL COOKIES: PRESS SPACE TO RESUME");
}

void	put_end_messsage(t_var_set *var)
{
	int	x;
	int	y;

	x = (var->map.column_count / 3) * TILE_SIZE;
	y = (var->map.row_count / 2) * TILE_SIZE;
	mlx_string_put(var->mlx, var->win, x, y, 0x000000,
		"GAME CLEAR: PRESS ESC TO QUIT");
}

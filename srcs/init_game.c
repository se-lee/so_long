/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:39:23 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 18:25:57 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_value(t_var_set *var)
{
	var->map.p_count = 0;
	var->map.c_count = 0;
	var->map.e_count = 0;
}

void	init_player_value(t_var_set *var)
{
	var->player.move_count = 0;
}

void	init_mlx_and_win(t_var_set *var)
{
	int	size_x;
	int	size_y;

	size_x = var->map.column_count * TILE_SIZE;
	size_y = var->map.row_count * TILE_SIZE;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, size_x, size_y, "so_long");
}

void	init_game(t_var_set *var)
{
	init_player_value(var);
	init_mlx_and_win(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:55:42 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 16:40:17 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

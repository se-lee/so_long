/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:50:23 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 14:50:25 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_put_to_win(t_var_set *var)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->player.image.ptr, var->player.x * TILE_SIZE,
		var->player.y * TILE_SIZE);
	return (0);
}

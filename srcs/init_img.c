/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:39:31 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 14:42:49 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_tile_img(t_var_set *var)
{
	var->tile.wall.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/sakura32.xpm", &(var->tile.wall.width),
			&(var->tile.wall.height));
	var->tile.space.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/grass32.xpm", &(var->tile.space.width),
			&(var->tile.space.height));
	var->tile.exit.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/house32.xpm", &(var->tile.exit.width),
			&(var->tile.exit.height));
}

void	init_player_img(t_var_set *var)
{
	var->player.image.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/short_hair_girl32.xpm", &(var->player.image.width),
			&(var->player.image.height));
}

void	init_collec_img(t_var_set *var)
{
	var->collec.image.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/cookie_32.xpm", &(var->collec.image.width),
			&(var->collec.image.height));
}

void	init_game_img(t_var_set *var)
{
	init_tile_img(var);
	init_player_img(var);
	init_collec_img(var);
}

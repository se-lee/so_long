/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:31:05 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 20:00:41 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_step_count_to_win(t_var_set *var)
{
	t_image img;

	img.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/black_square110.xpm", &(img.width), &(img.height));
	mlx_put_image_to_window(var->mlx, var->win, img.ptr, 0, 0);
	mlx_string_put(var->mlx, var->win, 8, 13, 0xFFFFFF, "STEP COUNT:");
	mlx_string_put(var->mlx, var->win, 90, 13, 0xFFFFFF, ft_itoa(var->player.move_count));
}

// void	put_start_messsage(t_var_set *var)
// {
// 	int	x;
// 	int	y;

// 	x = (var->map.column_count / 3) * TILE_SIZE;
// 	y = (var->map.row_count / 2) * TILE_SIZE;
// 	mlx_string_put(var->mlx, var->win, x, y, 0xFFFFFF, "PRESS SPACE TO START");
// }
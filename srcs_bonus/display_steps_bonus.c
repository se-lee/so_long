/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:31:05 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:01 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	put_step_count_to_win(t_var_set *var)
{
	t_image	img;
	char	*count;

	count = ft_itoa(var->player.move_count);
	img.ptr = mlx_xpm_file_to_image(var->mlx,
			"./assets_xpm/black_square110.xpm", &(img.width), &(img.height));
	mlx_put_image_to_window(var->mlx, var->win, img.ptr, 0, 0);
	mlx_string_put(var->mlx, var->win, 8, 13, 0xFFFFFF, "STEP COUNT:");
	mlx_string_put(var->mlx, var->win, 90, 13,
		0xFFFFFF, count);
	free(count);
}

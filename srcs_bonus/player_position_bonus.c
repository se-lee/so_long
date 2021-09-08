/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:04:22 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:35 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	player_get_coord(t_var_set *var)
{	
	int		i;
	int		j;

	i = 0;
	while (i < var->map.row_count)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			if (var->map.array[i][j] == 'P')
			{
				var->player.x_start = j;
				var->player.y_start = i;
				var->player.x = j;
				var->player.y = i;
			}
			j++;
		}
		i++;
	}
}

void	player_resume_position(t_var_set *var)
{
	var->player.x = var->player.x_start;
	var->player.y = var->player.y_start;
}

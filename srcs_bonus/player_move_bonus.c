/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:28 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 12:45:11 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	move_up(t_var_set *var)
{
	var->player.y--;
	var->player.move_count++;
}

void	move_down(t_var_set *var)
{
	var->player.y++;
	var->player.move_count++;
}

void	move_left(t_var_set *var)
{
	var->player.x--;
	var->player.move_count++;
}

void	move_right(t_var_set *var)
{
	var->player.x++;
	var->player.move_count++;
}

void	move_to_directions(t_var_set *var, int direction)
{
	if (!player_touched_wall(var, direction))
	{
		if (direction == DIR_UP)
			move_up(var);
		else if (direction == DIR_DOWN)
			move_down(var);
		else if (direction == DIR_LEFT)
			move_left(var);
		else if (direction == DIR_RIGHT)
			move_right(var);
		printf("step: %d \n", var->player.move_count);
	}
}

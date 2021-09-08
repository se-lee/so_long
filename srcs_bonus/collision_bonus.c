/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:43:08 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:46:55 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	player_touched_wall(t_var_set *var, int direction)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	return ((direction == DIR_UP && var->map.array[i - 1][j] == '1')
		|| (direction == DIR_DOWN && var->map.array[i + 1][j] == '1')
		|| (direction == DIR_LEFT && var->map.array[i][j - 1] == '1')
		|| (direction == DIR_RIGHT && var->map.array[i][j + 1] == '1'));
}

int	player_touched_collec(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	return (var->map.array[i][j] == 'C');
}

int	player_touched_exit(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	return (var->map.array[i][j] == 'E');
}

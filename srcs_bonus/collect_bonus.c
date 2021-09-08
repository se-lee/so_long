/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:20 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:46:54 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	collec_is_collected(t_var_set *var)
{
	if (player_touched_collec(var))
		var->map.array[var->player.y][var->player.x] = '0';
}

int	collec_all_collected(t_var_set *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.row_count)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			if (var->map.array[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

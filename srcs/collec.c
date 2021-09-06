/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:20 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 14:38:26 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collec_is_collected(t_var_set *var)
{
	if (player_touched_collec(var))
		var->map.array[var->player.y][var->player.x] = '0';
}

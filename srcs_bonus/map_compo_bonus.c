/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:59:59 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:27 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	map_count_compo(t_var_set *var, char c)
{
	if (c == 'P')
		var->map.p_count++;
	else if (c == 'C')
		var->map.c_count++;
	else if (c == 'E')
		var->map.e_count++;
}

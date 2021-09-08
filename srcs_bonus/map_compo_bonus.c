/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:59:59 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 17:05:01 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_count_compo(t_var_set *var, char c)
{
	if (c == 'P')
		var->map.p_count++;
	else if (c == 'C')
		var->map.c_count++;
	else if (c == 'E')
		var->map.e_count++;
}

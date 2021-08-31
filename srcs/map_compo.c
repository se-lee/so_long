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

void	map_get_player_coord(t_var_set *var)
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
				var->player.x = j;
				var->player.y = i;
//			printf("player:{%d, %d}\n", var->player.x, var->player.y);
			}
			j++;
		}
		i++;
	}
}

// void 	map_get_collec_coord();
/*
- need to store several coordinates of collectibles
*/
#include "../include/so_long.h"

void	collec_is_collected(t_var_set *var)
{
	if (player_touched_collec(var))
		var->map.array[var->player.y][var->player.x] = '0';
}

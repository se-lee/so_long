#include "../include/so_long.h"

/*
int		player_touched_wall(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	if (var->map.array[i][j] == '1')
		return (1);
	return (0);
}
*/

int		player_touched_wall(t_var_set *var, int direction)
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


int			player_touched_collec(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	return (var->map.array[i][j] == 'C');
}

int		player_touched_exit(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	return (var->map.array[i][j] == 'E');
}

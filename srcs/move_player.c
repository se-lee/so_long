#include "../include/so_long.h"

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
	}
}

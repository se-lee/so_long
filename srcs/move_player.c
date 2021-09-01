#include "../include/so_long.h"

/*
var->player.move_count++; is repetitive here..
*/

/*
make the player move only when wall is not met;

*/

void	move_up(t_var_set *var)
{
	var->player.y--;
	var->player.move_count++;
//can't go up if there is wall 
	
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

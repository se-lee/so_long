#include "../include/so_long.h"

// update coordinate and move count
void	move_up(t_var_set *var)
{
	var->player.y++;
	printf("x: %d  y:%d \n", var->player.x, var->player.y);
}

void	move_down(t_var_set *var)
{
	var->player.y--;
	printf("x: %d  y:%d \n", var->player.x, var->player.y);
}

void	move_left(t_var_set *var)
{
	var->player.x--;
	printf("x: %d  y:%d \n", var->player.x, var->player.y);
}

void	move_right(t_var_set *var)
{
	var->player.x++;
	printf("x: %d  y:%d \n", var->player.x, var->player.y);
}

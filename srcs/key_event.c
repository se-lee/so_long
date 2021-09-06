#include "../include/so_long.h"

int		key_direction(int keycode, t_var_set *var)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_to_directions(var, DIR_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_to_directions(var, DIR_DOWN);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_to_directions(var, DIR_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_to_directions(var, DIR_RIGHT);
	else if (keycode == KEY_ESC)
		exit(0);
printf("player:{%d, %d}\n", var->player.x, var->player.y);
	return (0);
}

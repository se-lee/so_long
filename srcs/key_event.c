#include "../include/so_long.h"

int		key_direction(int keycode, t_var_set *var)
{
	static int 	a = 0;

	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(var);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(var);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(var);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(var);
	else if (keycode == KEY_ESC)
		exit(0);
printf("player:{%d, %d}\n", var->player.x, var->player.y);
	return (0);
}

/*
usage:
mlx_hook(win_ptr, EVENT_KEY_PRESS, 1L<<0, &key_press, &param)
*/

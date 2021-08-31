#include "../include/so_long.h"

int		key_direction(int keycode, t_var_set *var)
{
	static int 	a = 0;

	if (keycode == KEY_W || keycode == KEY_UP)
		var->player.y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		var->player.y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		var->player.x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		var->player.x++;
	else if (keycode == KEY_ESC)
		exit(0);
	//	else
		//do nothing
printf("player:{%d, %d}\n", var->player.x, var->player.y);
	return (0);
}


int		key_press(int keycode, t_var_set *var)
{
	static int a = 0;

	if (keycode == KEY_W)
		var->player.x++;
	else if (keycode == KEY_S)
		var->player.x--;
	else if (keycode == KEY_ESC)
		exit(0);
	
	printf("x: %d\n", var->player.x);
	return (0);
}


/*
usage:
mlx_hook(win_ptr, EVENT_KEY_PRESS, 1L<<0, &key_press, &param)

*/
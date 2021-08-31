#include "../include/so_long.h"

int		exit_hook()
{
	exit(0);
}

int		exit_with_esc_key(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	exit_game(t_var_set *var)
{
	mlx_key_hook(var->win, exit_with_esc_key, &var);
	mlx_hook(var->win, EVENT_KEY_EXIT, 0, exit_hook, 0);
}
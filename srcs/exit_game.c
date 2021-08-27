#include "../include/so_long.h"

/* exit with esc key */
int	exit_hook()
{
	exit(0);
}

int	exit_with_esc_key(int esc_keycode, t_identifier *id)
{
	if (esc_keycode == KEY_ESC)
		exit(0);
	return (0);
}

/* exit with red cross button */
void	exit_game(t_identifier *id)
{
	mlx_key_hook(id->win, exit_with_esc_key, &id);
	mlx_hook(id->win, 17, 0, exit_hook, 0);
}

/*
when the window is closed with esc key, an error message comes up
" quit unexpectedly "
*/
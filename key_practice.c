#include <stdio.h>
#include <stdlib.h>
//#include "minilibx_mms_20210621/mlx.h"
#include "./minilibx_mms_20200219/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17

#define KEY_ESC				53
#define KEY_Q				12
#define KEY_W				13
#define KEY_E				14
#define KEY_R				15
#define KEY_A				0
#define KEY_S				1
#define KEY_D				2

typedef struct s_param
{
	int		x;
	int		y;
//	char 	str[3];
}	t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int		key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W) 
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	
	printf("x: %d\n", param->x);
	return (0);
}


int		main()
{
	void	*mlx;
	void	*win;
	t_param	param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "key");

	printf("--------------------\n");
	printf("W key: add 1 to x\n");
	printf("S key: subtract 1 from x\n");
	printf("ESC key: Exit program\n");
	printf("Others; print current x\n");
	printf("--------------------\n");

	printf("current x == 3\n");

	mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &param);
	mlx_loop(mlx);
}



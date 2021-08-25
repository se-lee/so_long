#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"

void	my_mlx_pixel_put(t_image *data, int x, int y) //, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dest = color;
}

int	main()
{
	t_identifier	vars;
	t_image	img;
	int		i;
	int		j;
	char	*relative_path = "./game_assets/test_green32.xpm";

	vars.mlx = mlx_init();
	img.width = 640;
	img.height = 256;
	vars.win = mlx_new_window(vars.mlx, img.width, img.height, "test");
	img.img_ptr = mlx_xpm_file_to_image(vars.mlx, relative_path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	// i = 0;
	// j = 0;
	// while (i < img.height - 32)
	// {
	// 	j = 0;
	// 	while (j < img.width - 32)
	// 	{
			my_mlx_pixel_put(&img, j, i); //, 0x70C9A1);
	// 		j = j + TILE_SIZE;
	// 	}
	// 	i = i + TILE_SIZE;
	// }
	// while (i < img_height - 1)
	// {
	// 	j = 0;
	// 	while (j <img_width - 1)
	// 	{
	// 		r = (double)(img_width - j) / (img_width - 1);
	// 		g = (double)(i) / (img_height - 1);
	// 		b = 1;
	// 		color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999) * b);
	// 		my_mlx_pixel_put(&img, j, i, color);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_put_image_to_window(vars.mlx, vars.win, img.img_ptr, 0, 0);
//	exit_game(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

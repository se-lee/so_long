#include "include/so_long.h"
#include "test.xpm"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	main()
{
	t_vars	vars;
	t_image	img;
	int		i;
	int		j;
	char	*relative_path = "./test.xpm";

	vars.mlx = mlx_init();
	img.width = 700;
	img.height = 500;
	vars.win = mlx_new_window(vars.mlx, img.width, img.height, "test");
	img.img_ptr = mlx_xpm_file_to_image(vars.mlx, relative_path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	i = 0;
	j = 0;
	while (i < 64)
	{
		my_mlx_pixel_put(&img, i, j, 0x2FC767);
		i = i + 16;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img_ptr, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

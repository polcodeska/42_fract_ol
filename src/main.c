#include "../include/fract_ol.h"
#include <stdio.h>

void	ft_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*mem_dst;;

	mem_dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)mem_dst = color;
}

void	ft_print_mandelbrot(t_fct_data *fct)
{
	double	min_x = -2.0;
	double	min_y = -1.2;
	double	max_x = 1.0;
	double	max_y = 1.2;
	double	g_point[2];
	double	x_factor = (max_x - min_x) / (WIN_WIDTH - 1);
	double	y_factor = (max_y - min_y) / (WIN_HEIGHT - 120 - 1);
	double	z;
	double	x_n;
	double	x_n_old;
	double	y_n;
	int		is_in_set;
	int		pxl_x;
	int		pxl_y;
	int		g_offset;
	int		i;
	int		max_iteration;

	pxl_x = 0;
	g_offset = 50;
	max_iteration = 30;
	while (pxl_x < WIN_WIDTH)
	{
		g_point[0] = min_x + (pxl_x * x_factor);
		pxl_y = 0;
		while (pxl_y < (WIN_HEIGHT - 120))
		{
			g_point[1] = max_y - (pxl_y * y_factor);
			is_in_set = 1;
			i = 0;
			x_n = g_point[0];
			y_n = g_point[1];
			while (i < max_iteration)
			{
				z = sqrt(x_n * x_n + y_n *y_n);
				if (z > 2)
				{
					is_in_set = 0;
					break;
				}
				x_n_old = x_n;
				x_n = x_n * x_n - y_n * y_n + g_point[0];
				y_n = 2 * x_n_old * y_n + g_point[1];
				i++;
			}
			if (is_in_set)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0x000000);
			else if (i > 10)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0x00FF00);
			else if (i > 8)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0x00FFFF);
			else if (i > 6)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0xFF00FF);
			else if (i > 4)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0xFFFFFF);
			else if (i > 2)
				ft_mlx_pixel_put(&fct->img, pxl_x+g_offset, pxl_y+60, 0xFFFF00);
			pxl_y++;
		}
		pxl_x++;
	}
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img.id, 0, 0);
}

int	main()
{
	t_fct_data fct;

	fct.mlx = mlx_init();
	if (!fct.mlx)
		return (1);
	fct.win = mlx_new_window(fct.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract’ol");
	if (!fct.win)
		return (1);
	fct.img.id = mlx_new_image(fct.mlx, WIN_WIDTH, WIN_HEIGHT);
	fct.img.addr = mlx_get_data_addr(fct.img.id, &fct.img.bits_per_pixel, \
			&fct.img.line_len, &fct.img.is_little_endian);
	ft_print_mandelbrot(&fct);
	mlx_loop(fct.mlx);
	return (0);
}

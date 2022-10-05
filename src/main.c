#include "../include/fract_ol.h"
#include <stdio.h>

int	main()
{
	t_fct *f;

	f = malloc(sizeof(*f));
	f->mlx = mlx_init();
	if (!f->mlx)
		return (1);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	if (!f->win)
		return (1);
	f->img = malloc(sizeof(*f->img));
	f->img->instance = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img->canvas = mlx_get_data_addr(f->img->instance,
			&f->img->bits_per_pixel, &f->img->line_len,
			&f->img->is_little_endian);
	mlx_hook(f->win, 17, 0, ft_exit, &f);
	mlx_hook(f->win, 2, 1, ft_handle_keys, f);
	ft_draw_mandelbrot(f);
	mlx_loop(f->mlx);
	return (0);
}

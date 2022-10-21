/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:04 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 21:20:37 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <stdio.h>

void	ft_init_graph(t_fct *f, char *fract_set)
{
	f->g->range_real = 3.5;
	f->g->range_im = 2.0;
	f->g->mid_real = -0.75;
	f->g->mid_im = 0.0;
	f->g->max_iter = 50;
	if (!ft_strncmp(fract_set, "Mandelbrot", 11))
		f->g->fract_set = MANDELBROT;
	else if (!ft_strncmp(fract_set, "Julia", 6))
	{
		f->g->fract_set = JULIA;
		f->g->mid_real += 0.2 * f->g->range_real;
	}
	f->g->c_real_julia = (double)264 / (double)WIN_WIDTH * f->g->range_real \
		+ f->g->mid_real - f->g->range_real / 2;
	f->g->c_im_julia = (double)594 / (double)WIN_HEIGHT * f->g->range_im + \
		f->g->mid_im - f->g->range_im / 2;
}

int	ft_init_fct(t_fct *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (1);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	f->img = malloc(sizeof(*f->img));
	f->g = malloc(sizeof(*f->g));
	if (!f->win || !f->img || !f->g)
		return (1);
	f->img->instance = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img->canvas = mlx_get_data_addr(f->img->instance,
			&f->img->bits_per_pixel, &f->img->line_len,
			&f->img->is_little_endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fct	*f;

	if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 11) || \
		!ft_strncmp(argv[1], "Julia", 6)))
	{
		f = malloc(sizeof(*f));
		if (!f)
			return (1);
		if (ft_init_fct(f))
			return (1);
		ft_init_graph(f, argv[1]);
		mlx_hook(f->win, 17, 0, ft_exit, f);
		mlx_hook(f->win, 2, 1L << 0, ft_handle_keys, f);
		mlx_mouse_hook(f->win, ft_handle_mouse, f);
		ft_draw(f);
		mlx_loop(f->mlx);
	}
	else
	{
		ft_putendl_fd("Fractol needs the prefered fractal set as argument.", 1);
		ft_putendl_fd("Possible arguments are \"Mandelbrot\" or \"Julia\"", 1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/27 15:32:03 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	ft_put_pxl_on_canvas(t_img *img, int g_pxl_x, int g_pxl_y, int color)
{
	char	*color_ptr;

	color_ptr = img->canvas + (g_pxl_y * img->line_len + g_pxl_x * \
			(img->bits_per_pixel / 8));
	*(unsigned int *)color_ptr = color;
}

void	ft_mandelbrot(t_fct *f, int x, int y)
{
	double	x_percentage;
	double	y_percentage;
	double	z_real;
	double	z_im;
	double	z_real_tmp;

	x_percentage = (double)x / (double)WIN_WIDTH;
	y_percentage = (double)y / (double)WIN_HEIGHT;
	f->g->c_real = x_percentage * f->g->range_real + f->g->mid_real - \
		f->g->range_real / 2;
	f->g->c_im = y_percentage * f->g->range_im + f->g->mid_im - \
		f->g->range_im / 2;
	f->g->c_im = -f->g->c_im;
	z_real = 0;
	z_im = 0;
	f->g->iter_count = 0;
	while (f->g->iter_count < f->g->max_iter && \
		(z_real * z_real + z_im * z_im) <= 4)
	{
		z_real_tmp = z_real * z_real - z_im * z_im + f->g->c_real;
		z_im = 2 * z_real * z_im + f->g->c_im;
		z_real = z_real_tmp;
		f->g->iter_count++;
	}
	ft_coloring_px_on_canvas(f, f->g->iter_count, x, y);
}

void	ft_julia(t_fct *f, int x, int y)
{
	double	z_real;
	double	z_im;
	double	z_real_tmp;
	int		iter_count;

	z_real = (double)x / (double)WIN_WIDTH * f->g->range_real + \
		f->g->mid_real - f->g->range_real / 2;
	z_im = (double)y / (double)WIN_HEIGHT * f->g->range_im + \
		f->g->mid_im - f->g->range_im / 2;
	z_im = -z_im;
	iter_count = 0;
	while (iter_count < f->g->max_iter && (z_real * z_real + z_im * z_im) <= 4)
	{
		z_real_tmp = z_real * z_real - z_im * z_im + f->g->c_real_julia;
		z_im = 2 * z_real * z_im + f->g->c_im_julia;
		z_real = z_real_tmp;
		iter_count++;
	}
	ft_coloring_px_on_canvas(f, iter_count, x, y);
}

void	ft_draw(t_fct *f)
{
	int		x;
	int		y;
	void	(*ft_fract_set)(t_fct *, int, int);

	if (f->g->fract_set)
		ft_fract_set = ft_mandelbrot;
	else
		ft_fract_set = ft_julia;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ft_fract_set(f, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->instance, 0, 0);
}

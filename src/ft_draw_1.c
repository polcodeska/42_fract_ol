/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 20:15:47 by tmasur           ###   ########.fr       */
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

void	ft_set_graph(t_fct *f)
{
	f->g->min_x = -2.0;
	f->g->min_y = -1.2;
	f->g->max_x = 2.0;
	f->g->max_y = 1.2;
	f->g->x_weight = (f->g->max_x - f->g->min_x) / (WIN_WIDTH - 1);
	f->g->y_weight = (f->g->max_y - f->g->min_y) / (WIN_HEIGHT - 1);
	f->g->max_iteration = 30;
	f->g->x_img = 0;
	ft_set_colors(f);
}

void	ft_mandelset(t_fct *f)
{
	double	z;
	double	x_on_g;
	double	y_on_g;
	double	x_on_g_tmp;

	x_on_g = f->g->x_fract;
	y_on_g = f->g->y_fract;
	while (f->g->iter_count < f->g->max_iteration)
	{
		z = x_on_g * x_on_g + y_on_g * y_on_g;
		if (z > 4)
			break ;
		x_on_g_tmp = x_on_g;
		x_on_g = x_on_g * x_on_g - y_on_g * y_on_g + f->g->x_fract;
		y_on_g = 2 * x_on_g_tmp * y_on_g + f->g->y_fract;
		f->g->iter_count++;
	}
}

void	ft_juliaset(t_fct *f)
{
	double	z;
	double	x_on_g;
	double	y_on_g;
	double	x_on_g_tmp;

	x_on_g = f->g->x_fract;
	y_on_g = f->g->y_fract;
	while (f->g->iter_count < f->g->max_iteration)
	{
		z = x_on_g * x_on_g + y_on_g * y_on_g;
		if (z > 4)
			break ;
		x_on_g_tmp = x_on_g;
		x_on_g = x_on_g * x_on_g - y_on_g * y_on_g + f->g->x_julia;
		y_on_g = 2 * x_on_g_tmp * y_on_g + f->g->y_julia;
		f->g->iter_count++;
	}
}

void	ft_draw_fract(t_fct *f, void (*ft_fractset)(t_fct *))
{
	ft_set_graph(f);
	while (f->g->x_img < WIN_WIDTH)
	{
		f->g->x_fract = f->g->min_x + (f->g->x_img * f->g->x_weight);
		f->g->y_img = 0;
		while (f->g->y_img < (WIN_HEIGHT))
		{
			f->g->y_fract = f->g->max_y - (f->g->y_img * f->g->y_weight);
			f->g->iter_count = 0;
			ft_fractset(f);
			ft_coloring_the_canvas(f);
			f->g->y_img++;
		}
		f->g->x_img++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->instance, 0, 0);
}

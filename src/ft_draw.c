/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 12:45:17 by tmasur           ###   ########.fr       */
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
	f->g->max_x = 1.0;
	f->g->max_y = 1.2;
	f->g->x_weight = (f->g->max_x - f->g->min_x) / (WIN_WIDTH - 1);
	f->g->y_weight = (f->g->max_y - f->g->min_y) / (WIN_HEIGHT - 1);
	f->g->max_iteration = 30;
}

void	ft_mandelset(t_fct *f)
{
	double	z;
	double	x_on_g;
	double	y_on_g;
	double	x_on_g_tmp;

	x_on_g = f->g->x;
	y_on_g = f->g->y;
	while (f->g->iter_count < f->g->max_iteration)
	{
		z = x_on_g * x_on_g + y_on_g * y_on_g;
		if (z > 4)
			break ;
		x_on_g_tmp = x_on_g;
		x_on_g = x_on_g * x_on_g - y_on_g * y_on_g + f->g->x;
		y_on_g = 2 * x_on_g_tmp * y_on_g + f->g->y;
		f->g->iter_count++;
	}
}

void	ft_juliaset(t_fct *f)
{
	// TODO: Code here
	;
}

void	ft_draw_fract(t_fct *f, void (*ft_fractset)(t_fct *))
{
	int		x;
	int		y;

	ft_set_graph(f);
	x = 0;
	while (x < WIN_WIDTH)
	{
		f->g->x = f->g->min_x + (x * f->g->x_weight);
		y = 0;
		while (y < (WIN_HEIGHT))
		{
			f->g->y = f->g->max_y - (y * f->g->y_weight);
			f->g->iter_count = 0;
			ft_fractset(f);
			if (f->g->iter_count >= 30)
				ft_put_pxl_on_canvas(f->img, x, y, 0x000000);
			else if (f->g->iter_count > 8)
				ft_put_pxl_on_canvas(f->img, x, y, 0x00FFFF);
			else if (f->g->iter_count > 6)
				ft_put_pxl_on_canvas(f->img, x, y, 0xFF00FF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->instance, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 20:01:20 by tmasur           ###   ########.fr       */
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

void	ft_mandelset(t_fct *f, int x, int y)
{
	double	x_percentage;
	double	y_percentage;
	double	c_real;
	double	c_im;
	double	z_real;
	double	z_im;
	double	z_real_tmp;
	int		iter_count;

	x_percentage = (double)x / (double)WIN_WIDTH;
	y_percentage = (double)y / (double)WIN_HEIGHT;
	c_real = x_percentage * f->g->range_real + f->g->mid_real - \
			 f->g->range_real / 2;
	c_im = y_percentage * f->g->range_im + f->g->mid_im - f->g->range_im / 2;
	z_real = 0;
	z_im = 0;
	iter_count = 0;
	while (iter_count < f->g->max_iter && (z_real * z_real + z_im * z_im) <= 4)
	{
		z_real_tmp = z_real * z_real - z_im * z_im + c_real;
		z_im = 2 * z_real * z_im + c_im;
		z_real = z_real_tmp;
		iter_count++;
	}
	ft_coloring_the_canvas(f, iter_count, x, y);
}

void	ft_draw(t_fct *f)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ft_mandelset(f, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->instance, 0, 0);
}

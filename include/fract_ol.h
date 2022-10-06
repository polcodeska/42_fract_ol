/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:08:02 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 11:04:54 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIN_HEIGHT 720
# define WIN_WIDTH 720

# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_graph {
	double	min_x_on_g;
	double	max_x_on_g;
	double	min_y_on_g;
	double	max_y_on_g;
	double	x_on_g;
	double	y_on_g;
	double	x_weight_on_g;
	double	y_weight_on_g;
	int		is_point_in_set;
	int		max_iteration;
	int		iter_count;
	int		color[20];
	int		x_on_img;
	int		y_on_img;
} t_graph;

typedef struct	s_img {
	void	*instance;
	char	*canvas;
	int		bits_per_pixel;
	int		line_len;
	int		is_little_endian;
}	t_img;

typedef struct	s_fct {
	void		*mlx;
	void		*win;
	t_img		*img;
} t_fct;

// ft_draw.c
void	ft_put_pxl_on_canvas(t_img *img, int pxl_x, int pxl_y, int color);
void	ft_draw_mandelbrot(t_fct *fct);

// ft_events.c
int		ft_exit(t_fct *fct);
int		ft_handle_keys(int key_pressed, t_fct *fct);
#endif


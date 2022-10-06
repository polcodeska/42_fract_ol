/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:08:02 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 15:21:40 by tmasur           ###   ########.fr       */
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
	char	*fract_set;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		x_img;
	int		y_img;
	double	x_fract;
	double	y_fract;
	double	x_julia;
	double	y_julia;
	double	x_weight;
	double	y_weight;
	int		iter_count;
	int		max_iteration;
	int		color[20];
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
	t_graph		*g;
} t_fct;

// ft_draw.c
void	ft_put_pxl_on_canvas(t_img *img, int pxl_x, int pxl_y, int color);
void	ft_mandelset(t_fct *f);
void	ft_juliaset(t_fct *f);
void	ft_draw_fract(t_fct *f, void (*ft_fractset)(t_fct *));
void	ft_clear_canvas(t_fct *f);

// ft_events.c
int		ft_exit(t_fct *f);
int		ft_handle_keys(int key_pressed, t_fct *f);
int		ft_julia_change(t_fct *f);
#endif


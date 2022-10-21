/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:08:02 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 19:46:04 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIN_HEIGHT 720
# define WIN_WIDTH 720
# define JULIA 0
# define MANDELBROT 1

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/include/libft.h"
# include <stdlib.h>

typedef struct s_graph {
	double	range_real;
	double	range_im;
	double	mid_real;
	double	mid_im;
	double	c_real;
	double	c_im;
	double	c_real_julia;
	double	c_im_julia;
	int		fract_set;
	int		max_iter;
	int		iter_count;
}	t_graph;

typedef struct s_img {
	void	*instance;
	char	*canvas;
	int		bits_per_pixel;
	int		line_len;
	int		is_little_endian;
}	t_img;

typedef struct s_fct {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_graph		*g;
}	t_fct;

// ft_draw.c
void	ft_put_pxl_on_canvas(t_img *img, int pxl_x, int pxl_y, int color);
void	ft_mandelbrot(t_fct *f, int x, int y);
void	ft_draw(t_fct *f);
void	ft_juliaset(t_fct *f);
void	ft_draw_fract(t_fct *f, void (*ft_fractset)(t_fct *));

// ft_draw_2.c
void	ft_clear_canvas(t_fct *f);
int		ft_get_color(int i);
void	ft_coloring_px_on_canvas(t_fct *f, int iter_count, int x, int y);

// ft_events.c
int		ft_exit(t_fct *f);
int		ft_handle_keys(int key_pressed, t_fct *f);
int		ft_handle_mouse(int btn, int x, int y, t_fct *f);
#endif
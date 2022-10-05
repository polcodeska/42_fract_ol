/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:08:02 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/05 09:43:26 by tmasur           ###   ########.fr       */
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

typedef struct	s_pxl {
	double	g_min_x;
	double	g_max_x;
	double	g_min_y;
	double	g_max_y;
} t_pxl;

typedef struct	s_img {
	void	*addr;
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:34:39 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:03:20 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "altlib/altlib.h"
# include "./minilibx-linux/mlx.h"
# include "./includes/keycodes_linux.h"
# include "./thread.h"
# include <math.h>
# include <pthread.h>
# define HGT 			400
# define WTH 			400
# define MAX_ITER 		100
# define BLACK 			0x000000
# define WHITE 			0xFFFFFF
# define MOTIONNOTIFY	6
# define ZOOM			1.1f

typedef enum		e_error_codes
{
	NO_SUCH_FRACTAL,
	NO_ARGS_PASSED,
	__ERROR_TOTAL,
}					t_e_error_codes;

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;

typedef enum		e_ftype
{
	NONE,
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	BRAIN,
	__FRACTAL_TOTAL
}					t_e_ftype;

typedef	struct		s_complex
{
	double		im;
	double		re;
}					t_complex;

typedef	struct		s_screen
{
	void		*server;
	void		*window;
}					t_screen;

typedef struct		s_mouse
{
	char		isdown;
	double		x;
	double		y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_complex	mouse;
}					t_viewport;

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef void		(*t_f_fn_v)(t_viewport *v);

typedef struct		s_fractal
{
	char		*name;
	t_f_fn_v	viewport;
	int			mouse;
}					t_fractal;

typedef struct		s_image
{
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef	struct		s_env
{
	t_screen	scr;
	t_e_ftype	fractal_type;
	t_fractal	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_render	render;
	double		zoom;
	double		x;
	double		y;
	int			smooth;
	t_palette	*palette;
	t_viewport	viewport;
	int			mouselock;
}					t_env;

t_pixel				draw_mandelbrot(int col, int row, t_viewport *viewport);
t_pixel				draw_julia(int col, int row, t_viewport *viewport,
						t_mouse mouse);
t_pixel				draw_burning_ship(int col, int row, t_viewport *viewport);
t_pixel				draw_brain(int col, int row, t_viewport *viewport,
						t_mouse mouse);

double				interpolate(double start, double end,
						double interpolation);
void				draw_hooks(int key, t_env *env);
int					key_hook(int keycode, t_env *env);

int					hook_mouseup(int button, int x, int y, t_env *env);
int					hook_mousemove(int x, int y, t_env *env);
int					hook_mousedown(int button, int x, int y, t_env *env);
int					hook_expose(t_env *env);

void				render(t_env *env);
void				*render_thread(void *m);
void				draw(t_env *env);

void				screen_init(t_env *env);
t_env				*mlxdel(t_env *env);
void				error_handler(char *err_str, int halt);

t_palette			*get_palettes(void);
void				pixel_to_image(char *img_str, int x, int y,
						uint32_t col);
void				image_set_pixel(t_image *image, int x, int y,
							int color);
void				clear_image(t_image *image);
t_image				*del_image(t_env *env, t_image *image);
t_image				*new_image(t_env *env);

void				julia_viewport(t_viewport *v);
void				mandelbrot_viewport(t_viewport *v);
void				burningship_viewport(t_viewport *v);
void				zoom(int x, int y, t_viewport *viewport, double z);
t_complex			screen_to_complex(int x, int y, t_viewport *v);
void				reset_viewport(t_env *env);
void				viewport_fit(t_viewport *v);
t_fractal			*fractal_match(char *str);
t_fractal			*get_fractals(void);
int					get_color(t_pixel p, t_env *env);
t_color				smooth_color(t_pixel p, int max, t_palette *pal);
t_color				linear_color(double i, int max, t_palette *p);
t_color				clerp(t_color c1, t_color c2, double p);
int					ft_lerpi(int first, int second, double p);

#endif

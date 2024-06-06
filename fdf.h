/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:49:42 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:42:33 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "libft/libft.h"
# include "ftprintf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

// structure to define x anf y coordinates to a pixel.
typedef struct s_coordinate {
	double	x;
	double	y;
	double	z;
}	t_point;

//Structure to contain  the projection matrix used to convert
// the x and y coordinates of each point.
typedef struct s_matrix {
	t_point	d;
	t_point	e;
	t_point	f;
}	t_matrix;

//structure of values needed for putting pixels betwwen two points.
typedef struct s_algorythm {
	int		a;
	int		b;
	int		p;
	int		xdiff;
	int		ydiff;
	int		zdiff;
	int		zstep;
	long	col;
	t_point	p_a;
	t_point	p_b;
	t_point	p_t;
}	t_pixel_line;

//structure containing information of the current map input 
// and its corelatin to the window.
typedef struct window_size_s {
	int32_t		width;
	int32_t		height;
	uint32_t	grid_h;
	uint32_t	grid_w;
	int			distance;
	long		background;
	long		colour;
	t_point		scale;
	t_point		angle;
	t_point		middle;
	t_point		tr;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		***grid;
}	t_window;

/*	array_utils	*/
void		ft_exit(char *msg);
void		free_grid(t_point ***arr, uint32_t h, uint32_t w);
void		ft_free_two_d_arr(void **arr);
int			arr_len(void **arr);
void		count_lines(char *argv, int *count);

/*	calc_utils	*/
int			ft_absolute(int a, int b);
void		error_check(void *p, char *msg);
int			calc_distance(int h, int w);
int			get_max_abs_value(t_point ***grid);
int			count_max_width(char *argv, int line_count);

/*	coordinate_utils	*/
int			get_grid_height(t_point ***grid);
int			get_grid_width(t_point ***grid);
t_point		find_midpoint(t_point ***grid);
void		correct_grid_coords(t_point ***grid, int w, int h, t_point tr);
void		apply_matrix_to_grid(t_point ***grid, t_matrix m, t_point middle);

/*	atol	*/
long		ft_atol(const char *str);

/*	draw_grid	*/
void		draw_grid(t_point ***grid, int height, t_window *size);
void		background(t_window *size);

/*	draw_line	*/
void		draw_line(t_point *point_a, t_point *point_b, t_window *size);

/*	initialize_grid_and_window	*/
t_point		**verify_line(char *line, u_int width);
t_point		***init_grid(char *argv, t_point ***grid);
void		put_coords_to_grid(t_point ***grid);
mlx_t		*fit_monitor_size(char *argv, int32_t *width, int32_t *height);
void		init_window(t_window *size);

/*	matrix_functions	*/
t_matrix	scale_matrix(t_point scale);
t_matrix	x_rot_matrix(double x_angle);
t_matrix	z_rot_matrix(double z_angle);
// t_matrix	y_rot_matrix(double y_angle);

/*	hook	*/
void		my_key_hook(mlx_key_data_t keydata, void *window);

/*	calculate_matrix	*/
t_point		point_matrix(t_point p, t_matrix m);
t_matrix	matrix_multiply(t_matrix m1, t_matrix m2);
t_matrix	get_full_matrix(t_point angle, t_point scale);

/*	put_new_imd_to_screen	*/
void		apply_matrix_to_grid(t_point ***grid, t_matrix m, t_point middle);
void		project(t_window *size);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:49:42 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 18:27:32 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define	FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "ftprintf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

//structure to contain parameters for a hook function.
typedef struct param_s {
	mlx_t		*mlx;
	mlx_image_t	*img;
}	param_t;

// structure to define x anf y coordinates to a pixel.
typedef struct s_coordinate {
	uint32_t		x;
	uint32_t		y;
} t_point;

//structure of values needed for putting pixels betwwen two points.
typedef struct s_algorythm {
	int	a;
	int	b;
	int	p;
	int	xdiff;
	int	ydiff;
	long	colour;
	t_point	point_a;
	t_point	point_b;
	t_point	point_t;
}	t_pixel_line_algorythm;

//Structure containing value and colour of each point in the map input.
typedef struct s_grid {
	int				value;
	unsigned int	colour;
	t_point			pnt;
}	t_grid;

//structure containing information of the current map input 
// and its corelatin to the window.
typedef struct window_size_s {
	int	width;
	int	height;
	uint32_t	grid_w;
	uint32_t	grid_h;
	int	distance;
	int border;
}	t_window;

void		ft_exit(void);
int			count_lines(char *argv);
void		free_grid(t_grid ***arr, uint32_t h, uint32_t w);
void 		ft_free_2D_arr(void **arr);
int			arr_len(void **arr);
long		ft_atol(const char *str);
int			ft_absolute(int a, int b);
t_grid		***get_grid(char *argv, long colour);
int			get_grid_width(t_grid ***grid);
void		draw_line(mlx_image_t *img, t_point point_a, t_point point_b, long colour);
t_window	calc_img_size_isometric(t_grid ***grid);
int			calc_distance(int h, int w);
int			get_value_range(t_grid ***grid);
void		connect_grid_with_lines(mlx_image_t *img, t_grid ***grid, int height);
int			count_max_width(char *argv);







// test_tries
void ft_hook(param_t *param);
void my_key_hook(mlx_key_data_t keydata, void *mlx);


#endif 
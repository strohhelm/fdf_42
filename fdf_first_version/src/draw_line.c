/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:34:23 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 18:54:08 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

void	draw_line_x(mlx_image_t *img, t_pixel_line_algorythm z)
{
		z.a = 2 * z.ydiff;
		z.b = z.a - 2 * z.xdiff;
		z.p = z.a - z.xdiff;
		while (z.xdiff > 0)
		{
			if (z.point_a.x < z.point_b.x)
				z.point_t.x++;
			else
				z.point_t.x--;
			if (z.p < 0)
				z.p += z.a;
			else
			{
				if (z.point_a.y > z.point_b.y)
					z.point_t.y--;
				else
					z.point_t.y++;
				z.p += z.b;
			}
			if (z.point_t.x >= 0 && z.point_t.y >= 0)
				mlx_put_pixel(img, z.point_t.x, z.point_t.y, z.colour);
			z.xdiff--;
		}
}

void	draw_line_y(mlx_image_t *img, t_pixel_line_algorythm z)
{
	z.a = 2 * z.xdiff;
	z.b = z.a - 2 *z.ydiff;
	z.p = z.a - z.ydiff;
	while (z.ydiff > 0)
	{
		if (z.point_a.y < z.point_b.y)
			z.point_t.y++;
		else
			z.point_t.y--;
		if (z.p < 0)
			z.p += z.a;
		else
		{
			if (z.point_a.x > z.point_b.x)
				z.point_t.x--;
			else
				z.point_t.x++;
			z.p += z.b;
		}
		if (z.point_t.x >= 0 && z.point_t.y >= 0)
			mlx_put_pixel(img, z.point_t.x, z.point_t.y, z.colour);
		z.ydiff--;
	}
}

void	draw_line(mlx_image_t *img, t_point point_a, t_point point_b, long colour)
{
	t_pixel_line_algorythm	z;

	z.point_a = point_a;
	z.point_b = point_b;
	z.point_t = point_a;
	z.colour = colour;
	z.xdiff = ft_absolute(point_a.x, point_b.x);
	z.ydiff = ft_absolute(point_a.y, point_b.y);
	mlx_put_pixel(img, point_a.x, point_a.y, colour);
	if (z.xdiff >= z.ydiff)
		draw_line_x(img, z);
	else if (z.ydiff > z.xdiff)
		draw_line_y(img, z);
	mlx_put_pixel(img, point_b.x, point_b.y, colour);
	return ;
}

// int	main(int argc, char *argv[])
// {
// 	t_window	size;

// 	if (argc == 6)
// 	{
// 	size.width = 1024;
// 	size.height = 1024;
// 	mlx_t* mlx = mlx_init(size.width, size.height, "WTF", true);
// 	if (!mlx)
// 		ft_exit();
// 	mlx_image_t* img = mlx_new_image(mlx, size.width, size.height);
// 	// draw_line(img, &argv[1]);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_exit();
	
// 	mlx_key_hook(mlx, &my_key_hook, (void *)mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	}
// 	return (EXIT_SUCCESS);
// } 
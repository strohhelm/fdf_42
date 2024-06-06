/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:20 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 21:58:46 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	draw_grid_zero_zero(double x, double y, t_window *size)
{
	if (!(x < 0 || x > size-> width) && !(y < 0 || y > size->height))
		mlx_put_pixel(size->img, x, y, size->colour);
}

void	draw_grid(t_point ***grid, int height, t_window *size)
{
	int	i;
	int	j;
	int	w_current;
	int	w_next;

	i = 0;
	draw_grid_zero_zero(grid[0][0]->x, grid[0][0]->y, size);
	while (grid[i])
	{
		j = 0;
		w_current = arr_len((void **)grid[i]);
		if (i < height - 1)
			w_next = arr_len((void **)grid[i + 1]);
		else
			w_next = 0;
		while (j < w_current)
		{
			if (j < w_next)
				draw_line(grid[i][j], grid[i + 1][j], size);
			if (j != w_current -1)
				draw_line(grid[i][j], grid[i][j + 1], size);
			j++;
		}
		i++;
	}
}

void	background(t_window *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size->height)
	{
		j = 0;
		while (j < size->width)
		{
			mlx_put_pixel(size->img, j, i, size->background);
			j++;
		}
		i++;
	}
	return ;
}

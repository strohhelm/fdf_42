/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_new_img_to_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:11:08 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 17:00:44 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_matrix_to_grid(t_point ***grid, t_matrix m, t_point middle)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			grid[i][j]->x -= middle.x;
			grid[i][j]->y -= middle.y;
			*(grid[i][j]) = point_matrix(*(grid[i][j]), m);
			grid[i][j]->x += middle.x;
			grid[i][j]->y += middle.y;
			j++;
		}
		i++;
	}
}

void	project(t_window *size)
{
	t_matrix		m;

	m = get_full_matrix(size->angle, size->scale);
	size->img = mlx_new_image(size->mlx, size->width, size->height);
	if (!size->img)
		ft_exit("failed to allocate new img");
	background(size);
	apply_matrix_to_grid(size->grid, m, size->middle);
	correct_grid_coords(size->grid, size->width, size->height, size->tr);
	draw_grid(size->grid, size->grid_h, size);
	if ((mlx_image_to_window(size->mlx, size->img, 0, 0) < 0))
		ft_exit("failed to put img to window");
}

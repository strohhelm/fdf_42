/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_grid_with_lies.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:20 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 19:00:01 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	connect_grid_with_lines(mlx_image_t *img, t_grid ***grid, int height)
{
	int	i;
	int	j;
	int w_current;
	int	w_next;

	i = 0;
	while (grid[i])
	{
		j = 0;
		w_current = arr_len((void **)grid[i]);
		if (i < height - 1)
		{
			printf("i = %d\n", i);
			w_next = arr_len((void **)grid[i + 1]);
		}
		else 
			w_next = 0;
		while (j < w_current)
		{
				printf("w_c:%d | w_n:%d | i:%d | j:%d\n", w_current, w_next, i, j);
				if (j < w_next)
					draw_line(img, grid[i][j]->pnt, grid[i + 1][j]->pnt, 0x00ffafff);
				if (j != w_current -1)
					draw_line(img, grid[i][j]->pnt, grid[i][j + 1]->pnt, 0x00ffafff);
			j++;
		}
		printf("--------\n");
		i++;
	}
}

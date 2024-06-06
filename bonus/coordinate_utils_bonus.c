/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:38 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 16:06:27 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

int	get_grid_height(t_point ***grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		i++;
	}
	return (i);
}

int	get_grid_width(t_point ***grid)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			j++;
			if (j > width)
				width = j;
		}
		i++;
	}
	return (width);
}

void	find_midpoint_second(t_point ***grid, int i, t_point *max, t_point *min)
{
	int	j;

	j = 0;
	while (grid[i][j])
	{
		if (grid[i][j]->x > max->x)
			max->x = grid[i][j]->x;
		if (grid[i][j]->x < min->x)
			min->x = grid[i][j]->x;
		if (grid[i][j]->y > max->y)
			max->y = grid[i][j]->y;
		if (grid[i][j]->y < min->y)
			min->y = grid[i][j]->y;
		if (grid[i][j]->z > max->z)
			max->z = grid[i][j]->z;
		if (grid[i][j]->z < min->z)
			min->z = grid[i][j]->z;
		j++;
	}
}

t_point	find_midpoint(t_point ***grid)
{
	t_point	max;
	t_point	min;
	t_point	middle;
	int		i;

	max.x = __FLT_MIN__;
	max.y = __FLT_MIN__;
	max.z = __FLT_MIN__;
	min.x = __FLT_MAX__;
	min.y = __FLT_MAX__;
	min.z = __FLT_MAX__;
	i = 0;
	while (grid[i])
	{
		find_midpoint_second(grid, i, &max, &min);
		i++;
	}
	middle.x = fabs(max.x - min.x) / 2;
	middle.y = fabs(max.y - min.y) / 2;
	middle.z = fabs(max.z - min.z) / 2;
	return (middle);
}

void	correct_grid_coords(t_point ***grid, int width, int height, t_point tr)
{
	int			i;
	int			j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			grid[i][j]->x += (width / 2) + tr.x;
			grid[i][j]->y += (height / 2) + tr.y;
			j++;
		}
		i++;
	}
}

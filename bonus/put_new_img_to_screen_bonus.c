/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_new_img_to_screen_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:11:08 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 21:14:51 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	copy_grid_line(t_point ***grid, t_point **work_grid, int i, int grid_w)
{
	int	j;

	j = 0;
	while (j < grid_w)
	{
		work_grid[j] = (t_point *)malloc(sizeof(t_point));
		if (!work_grid[j])
			ft_exit("malloc failed while copying grid");
		if (grid[i][j])
			ft_memcpy(work_grid[j], grid[i][j], sizeof(t_point));
		else
			work_grid[j] = NULL;
		j++;
	}
	work_grid[j] = NULL;
}

t_point	***copy_grid(t_point ***grid, int grid_h, int grid_w)
{
	t_point	***work_grid;
	int		i;

	work_grid = (t_point ***)malloc((grid_h + 1) * sizeof(t_point **));
	if (!work_grid)
		ft_exit("malloc failed while copying grid");
	i = 0;
	while (i < grid_h)
	{
		work_grid[i] = (t_point **)malloc(sizeof(t_point *) * (grid_w + 1));
		if (!work_grid[i])
			ft_exit("malloc failed while copying grid");
		copy_grid_line(grid, work_grid[i], i, grid_w);
		i++;
	}
	work_grid[i] = NULL;
	return (work_grid);
}

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

void	set_work_grid(t_point ***grid, t_point ***work_grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			ft_memcpy(work_grid[i][j], grid[i][j], sizeof(t_point));
			j++;
		}
		i++;
	}
}

void	project(t_window *size)
{
	t_matrix		m;

	set_work_grid(size->grid, size->work_grid);
	m = get_full_matrix(size->angle, size->scale);
	size->img = mlx_new_image(size->mlx, size->width, size->height);
	if (!size->img)
		ft_exit("failed to allocate new img");
	background(size);
	apply_matrix_to_grid(size->work_grid, m, size->middle);
	correct_grid_coords(size->work_grid, size->width, size->height, size->tr);
	draw_grid(size->work_grid, size->grid_h, size);
	if (mlx_image_to_window(size->mlx, size->img, 0, 0) < 0)
		ft_exit("failed to put img to window");
	if (!mlx_put_string(size->mlx, "Rotate: Arrow Keys", 50, 50)
		|| !mlx_put_string(size->mlx, "Translate: W, A, S, D", 50, 100)
		|| !mlx_put_string(size->mlx, "Preset colour: C", 50, 150)
		|| !mlx_put_string(size->mlx, "Random colour: V", 50, 200)
		|| !mlx_put_string(size->mlx, "Random backgroung: G", 50, 250)
		|| !mlx_put_string(size->mlx, "Black background: H", 50, 300)
		|| !mlx_put_string(size->mlx, "Zoom: scroll", 50, 350)
		|| !mlx_put_string(size->mlx, "Change Z: SPACE + scroll", 50, 400)
		|| !mlx_put_string(size->mlx, "Isometric View: R", 50, 450)
		|| !mlx_put_string(size->mlx, "Bimetric View: B", 50, 500))
		ft_exit("String on window failed");
}

	// if (size->perspective_flag)
	// 	apply_perspective(size->work_grid, size);
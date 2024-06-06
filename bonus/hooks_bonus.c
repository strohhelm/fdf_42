/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:01:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 17:12:46 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	my_key_hook(mlx_key_data_t keydata, void *window)
{
	t_window	*size;
	int			flag;

	size = (t_window *)window;
	flag = 0;
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
		flag = change_accordingly(keydata, size);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		change_colour(&size->colour);
		flag = 1;
	}
	if (!flag)
		return ;
	mlx_delete_image(size->mlx, size->img);
	size->img = NULL;
	project(size);
}

void	my_scroll_hook(double xdelta, double ydelta, void *window)
{
	t_window	*size;

	size = (t_window *)window;
	if (check_keys(ydelta, size))
		;
	else if (ydelta > 0)
	{
		size->scale.x++;
		size->scale.y++;
		size->scale.z++;
	}
	else if (ydelta < 0)
	{
		size->scale.x--;
		size->scale.y--;
		size->scale.z--;
	}
	mlx_delete_image(size->mlx, size->img);
	size->img = NULL;
	project(size);
	xdelta += 0;
}

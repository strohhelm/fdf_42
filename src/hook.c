/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:01:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:32:02 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_key_hook(mlx_key_data_t keydata, void *window)
{
	t_window	*size;

	size = (t_window *)window;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_grid(size->grid, size->grid_h, size->grid_w);
		mlx_delete_image(size->mlx, size->img);
		mlx_terminate((mlx_t *)size->mlx);
		exit(0);
	}
}

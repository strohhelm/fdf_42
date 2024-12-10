/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:01:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/24 20:01:30 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void ft_hook(param_t *param)
{
	static int32_t	x;
	static int32_t	y;
	
	
	if (mlx_is_mouse_down(param->mlx, MLX_MOUSE_BUTTON_LEFT))
		{
			mlx_get_mouse_pos(param->mlx, &x, &y);
			if (x > 0 && y > 0)
				mlx_put_pixel(param->img, x, y, 0x00FF00FF);
		}
	return ;
}
void my_key_hook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate((mlx_t *)mlx);
		exit(0);
	}
}
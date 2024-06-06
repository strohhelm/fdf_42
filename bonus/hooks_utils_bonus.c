/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:22:33 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:52:17 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

long	get_random_colour(void)
{
	long	colour;
	int		r;
	int		g;
	int		b;
	int		a;

	r = rand();
	g = rand();
	b = rand();
	a = 255;
	colour = r << 24 | g << 16 | b << 8 | a;
	return (colour);
}

void	change_colour(long	*colour)
{
	static int	count = 1;

	if (count == 10)
		count = 0;
	if (count == 1)
		*colour = 0xe6194bff;
	if (count == 2)
		*colour = 0xf58231ff;
	if (count == 3)
		*colour = 0xffe1190ff;
	if (count == 4)
		*colour = 0xbfee62ff;
	if (count == 5)
		*colour = 0x3cb44bff;
	if (count == 6)
		*colour = 0x42d4f4ff;
	if (count == 7)
		*colour = 0x4363d8ff;
	if (count == 8)
		*colour = 0x911eb4ff;
	if (count == 9)
		*colour = 0xfabebeff;
	count++;
}

int	change_accordingly_second(mlx_key_data_t keydata, t_window *size)
{
	if (keydata.key == MLX_KEY_A)
		return (size->tr.x -= 10, 1);
	else if (keydata.key == MLX_KEY_D)
		return (size->tr.x += 10, 1);
	else if (keydata.key == MLX_KEY_W)
		return (size->tr.y -= 10, 1);
	else if (keydata.key == MLX_KEY_S)
		return (size->tr.y += 10, 1);
	else if (keydata.key == MLX_KEY_B)
		return (size->angle.x = 90 - 20.9066, size->angle.z = 45, 1);
	else if (keydata.key == MLX_KEY_R)
		return (size->angle.x = 90 - 35.264, size->angle.z = 45, 1);
	else if (keydata.key == MLX_KEY_G)
		return (size->background = get_random_colour());
	else if (keydata.key == MLX_KEY_H)
		return (size->background = 0x000000ff);
	else if (keydata.key == MLX_KEY_V)
		return (size->colour = get_random_colour());
	else
		return (0);
}
		// system("leaks fdf");

int	change_accordingly(mlx_key_data_t keydata, t_window *size)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_grid(size->grid, size->grid_h, size->grid_w);
		mlx_delete_image(size->mlx, size->img);
		mlx_terminate((mlx_t *)size->mlx);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_UP)
		return (size->angle.x += 5, 1);
	else if (keydata.key == MLX_KEY_DOWN)
		return (size->angle.x -= 5, 1);
	else if (keydata.key == MLX_KEY_LEFT)
		return (size->angle.z += 5, 1);
	else if (keydata.key == MLX_KEY_RIGHT)
		return (size->angle.z -= 5, 1);
	else
		return (change_accordingly_second(keydata, size));
}

int	check_keys(double ydelta, t_window *size)
{
	if (ydelta > 0 && mlx_is_key_down(size->mlx, MLX_KEY_SPACE))
		return (size->scale.z++, 1);
	else if (ydelta < 0 && mlx_is_key_down(size->mlx, MLX_KEY_SPACE))
		return (size->scale.z--, 1);
	else
		return (0);
}
	// else if (ydelta > 0 && mlx_is_key_down(size->mlx, MLX_KEY_F))
	// 	return (size->focal_l++, 1);
	// else if (ydelta < 0 && mlx_is_key_down(size->mlx, MLX_KEY_F))
	// 	return (size->focal_l--, 1);

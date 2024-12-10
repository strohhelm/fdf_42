/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:53:41 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 19:57:45 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	get_start_position(t_window *size)
{
	t_point p;
	
	p.y = size->border + 1;
	p.x = size->width - size->border - (size->grid_w - 1) * size->distance;
	printf("total width: %d\ntotal height: %d\n", size->width, size->height);
	printf("grid height: %d\ngrid width: %d\n", size->grid_h, size->grid_w);
	return (p);
}

void	put_coords_to_grid(t_grid ***grid, t_window *size)
{
	t_point	p;
	t_point	t;
	t_point	i;
	int		v_range;
	int		y_deflect;
	i.x = 0;
	v_range = get_value_range(grid);
	printf("value range: %d\n",v_range);
	p = get_start_position(size);
	while (i.x < size->grid_h)
	{
		t.x = p.x - (i.x * size->distance);
		t.y = p.y + (i.x * size->distance/2);
		i.y = 0;
		while (i.y < size->grid_w && grid[i.x][i.y])
		{
			y_deflect = (int)round((float)grid[i.x][i.y]->value /
						(float)v_range * (size->distance));
			grid[i.x][i.y]->pnt.x = t.x + i.y * size->distance;
			grid[i.x][i.y]->pnt.y = t.y + i.y * size->distance / 2 - y_deflect;
			i.y++;
		}
		i.x++;
	}
}



void	put_grid_to_img(mlx_image_t *img, t_grid ***grid, t_window *size)
{
	uint16_t	dis;
	uint32_t	i;
	uint32_t	j;

	dis = size->distance;
	i = 0;

	while (i < size->grid_h)
	{
		j = 0;
		while (j < size->grid_w && grid[i][j])
		{
			mlx_put_pixel(img, grid[i][j]->pnt.x, grid[i][j]->pnt.y,
							grid[i][j] -> colour);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_window	size;
	t_grid		***grid;
	long		colour = 0xffff00ff;

	if (argc == 2)
	{
		grid = get_grid(argv[1], colour);
		size = calc_img_size_isometric(grid);
		int i = 0;
		int j = 0;
		// while (i < size.grid_h)
		// {
		// 	j = 0;
		// 	while (j <= size.grid_w)
		// 	{
		// 		printf("%15p ", grid[i][j]);
		// 		j++;
		// 	}
		// 	i++;
		// 	printf("\n\n");
		// }
		// printf("-------------------------------------------------------\n\n");
		mlx_t* mlx = mlx_init(size.width, size.height, argv[1], true);
		if (!mlx)
			ft_exit();
		mlx_image_t* img = mlx_new_image(mlx, size.width, size.height);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_exit();

		put_coords_to_grid(grid, &size);
		put_grid_to_img(img, grid, &size);
		i = 0;
		 j = 0;
		while (i < size.grid_h)
		{
			j = 0;
			while (j <= size.grid_w)
			{
				printf("%15p ", grid[i][j]);
				j++;
			}
			i++;
			printf("\n\n");
		}
		connect_grid_with_lines(img, grid, size.grid_h);

		

		mlx_key_hook(mlx, &my_key_hook, (void *)mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free_grid(grid, size.grid_h, size.grid_w);
		exit (0);
	}
	return (EXIT_SUCCESS);
}

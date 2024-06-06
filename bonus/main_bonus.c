/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:53:41 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:30:54 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

// system("leaks fdf");
int	main(int argc, char *argv[])
{
	t_window	size;

	if (argc == 2)
	{
		if (!ft_strchr(argv[1], '.')
			|| ft_strncmp(ft_strrchr(argv[1], '.'), ".fdf\0", 5))
			ft_exit("Whoops, thats not a .fdf file");
		size.grid = init_grid(argv[1], NULL);
		size.mlx = fit_monitor_size(argv[1], &size.width, &size.height);
		init_window(&size);
		size.work_grid = copy_grid(size.grid, size.grid_h, size.grid_w);
		project(&size);
		mlx_key_hook(size.mlx, &my_key_hook, (void *)&size);
		mlx_scroll_hook(size.mlx, &my_scroll_hook, (void *)&size);
		mlx_loop(size.mlx);
		mlx_terminate(size.mlx);
		free_grid(size.grid, size.grid_h, size.grid_w);
		free_grid(size.work_grid, size.grid_h, size.grid_w);
		exit(0);
	}
	if (argc > 2)
		ft_printf(1, "Whoops, too many arguments.\n");
	else
		ft_printf(1, "ERROR: No input specified\n");
	return (EXIT_FAILURE);
}

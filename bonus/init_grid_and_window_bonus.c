/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid_and_window_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:42:40 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:55:27 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

t_point	**verify_line(char *line, u_int width)
{
	u_int		j;
	char		**split_line;
	t_point		**line_arr;

	j = 0;
	line = ft_strtrim(line, "\n");
	split_line = ft_split(line, ' ');
	free(line);
	error_check((void *)split_line, "ft_split failed");
	line_arr = (t_point **)malloc((width + 1) * sizeof(t_point *));
	error_check((void *)line_arr, "line_arr malloc failed");
	while (split_line[j])
	{
		line_arr[j] = (t_point *)malloc(sizeof(t_point));
		error_check((void *)line_arr[j], "line_arr[j] malloc failed");
		line_arr[j]->z = ft_atol(split_line[j]);
		j++;
	}
	while (j <= width)
		line_arr[j++] = NULL;
	ft_free_two_d_arr((void **)split_line);
	return (line_arr);
}

t_point	***init_grid(char *argv, t_point ***grid)
{
	int		fd;
	char	*line;
	int		i;
	int		line_count;
	int		width;

	i = 0;
	count_lines(argv, &line_count);
	width = count_max_width(argv, line_count);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit("could not open file");
	grid = (t_point ***)malloc((line_count + 1) * sizeof(t_point **));
	while (i < line_count)
	{
		line = get_next_line(fd);
		error_check((void *)line, "get_next_line failed");
		grid[i] = verify_line(line, width);
		free(line);
		i++;
	}
	grid[line_count] = NULL;
	close(fd);
	return (grid);
}

void	put_coords_to_grid(t_point ***grid)
{
	int			i;
	int			j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			grid[i][j]->x = j;
			grid[i][j]->y = i;
			j++;
		}
		i++;
	}
}

mlx_t	*fit_monitor_size(char *argv, int32_t *width, int32_t *height)
{
	int32_t	w;
	int32_t	h;
	mlx_t	*mlx;

	mlx = mlx_init(100, 100, argv, false);
	if (!mlx)
		ft_exit("failed to get window instance");
	mlx_get_monitor_size(0, &w, &h);
	mlx_set_window_size(mlx, w - 100, h - 100);
	mlx_set_window_pos(mlx, 50, 50);
	*width = w - 100;
	*height = h - 100;
	return (mlx);
}

void	init_window(t_window *size)
{
	size->grid_h = get_grid_height(size->grid);
	size->grid_w = get_grid_width(size->grid);
	size->distance = calc_distance(size->grid_h, size->grid_w);
	size->colour = 0x6cf542ff;
	size->scale.x = size->distance;
	size->scale.y = size->distance;
	size->scale.z = size->distance;
	size->angle.x = 90 - 35.264;
	size->angle.y = 0;
	size->angle.z = 45;
	put_coords_to_grid(size->grid);
	size->middle = find_midpoint(size-> grid);
	size->tr.x = size->middle.x * -1;
	size->tr.y = size->middle.y * -1;
	if (size->middle.z > size->middle.x
		&& size->middle.z > size->middle.y)
		size->tr.y = size->height / 4;
	size->background = 0x000000ff;
	return ;
}

	// size->perspective_flag = 0;
	// size->focal_l = 1;
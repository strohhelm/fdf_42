/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_from_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:42:40 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 17:55:59 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_grid	**verify_line(char *line, int width, long colour)
{
	int		j;
	char	**split_line;
	t_grid	**line_arr;

	j = 0;
	split_line = ft_split(line, ' ');
	if (!split_line)
		ft_exit();
	while (split_line[j])
		j++;
	free(split_line[j - 1]);
	split_line[j - 1] = NULL;
	free(split_line[j]);
	j = 0;
	line_arr = (t_grid **)malloc((width + 1) * sizeof(t_grid *));
	while(split_line[j])
	{
		line_arr[j] = (t_grid *)malloc(sizeof(t_grid));
		line_arr[j]->value = ft_atol(split_line[j]);
		if (strchr(split_line[j], ','))
			line_arr[j]->colour = ft_atol(ft_strchr(line, ',') + 1);
		else
			line_arr[j]->colour = colour;
		j++;
	}
	while (j <= width)
		line_arr[j++] = NULL;
	ft_free_2D_arr((void **)split_line);
	return(line_arr);
}

t_grid	***get_grid(char *argv, long colour)
{
	int		fd;
	char	*line;
	int		i;
	int		line_count;
	t_grid	***grid;
	int		width;

	i = 0;
	line_count = count_lines(argv);
	width = count_max_width(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit();
	line = get_next_line(fd);
	if (!line)
		ft_exit();
	grid = (t_grid ***)malloc((line_count + 1) * sizeof(t_grid **));
	while (i < line_count && line)
	{
		grid[i] = verify_line(line, width, colour);
		i++;
		line = get_next_line(fd);
	}
	grid[line_count] = NULL;
	close(fd);
	return (grid);
}

int	get_grid_height(t_grid ***grid)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}

int	get_grid_width(t_grid ***grid)
{
	int	i;
	int	j;
	int width;

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

//width = 1 + (h -1) * d + (w - 1) * d
//height = 12 + (h - 1) * d/2 + (w - 1) * d/2
t_window	calc_img_size_isometric(t_grid ***grid)
{
	t_window	size;
	int			h;
	int			w;
	int			dist;

	h = get_grid_height(grid);
	w = get_grid_width(grid);
	size.distance = calc_distance(h, w);
	size.border = 100;
	dist = size.distance;
	size.grid_h = h;
	size.grid_w = w;

	size.width = 1 + (h + w - 2) * dist + 2 * size.border;
	size.height = 1 + (h + w - 2) * dist / 2 + 2 * size.border;
	return (size);
}	
//  longer = ((x - y) >= 0) * x + ((x - y) < 0) * y;
// shorter = ((x - y) >= 0) * y + ((x - y) < 0) * x;
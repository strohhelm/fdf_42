/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:59 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 16:06:24 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

int	ft_absolute(int a, int b)
{
	int	nb;

	nb = a - b;
	return ((nb >= 0) * nb + (nb < 0) * -1 * nb);
}

void	error_check(void *p, char *msg)
{
	if (!p)
		ft_exit(msg);
}

int	calc_distance(int h, int w)
{
	int	dist;

	dist = 0;
	if (h + w <= 30)
		dist = 50;
	else if (h + w <= 100)
		dist = 25;
	else if (h + w <= 250)
		dist = 10;
	else if (h + w <= 500)
		dist = 6;
	else if (h + w <= 1000)
		dist = 3;
	else
		dist = 1;
	return (dist);
}

int	get_max_abs_value(t_point ***grid)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	max = INT_MIN;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (fabs(grid[i][j]->z) > max)
				max = grid[i][j]->z;
			j++;
		}
		i++;
	}
	return (max);
}

int	count_max_width(char *argv, int line_count)
{
	int		i;
	int		fd;
	int		max;
	char	*line;
	char	**tmp;

	max = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit("file not found");
	while (line_count > 0)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit("get_netxt_line failed");
		tmp = ft_split(line, ' ');
		free(line);
		i = arr_len((void **)tmp);
		if (i > max)
			max = i;
		ft_free_two_d_arr((void *)tmp);
		line_count--;
	}
	close(fd);
	return (max);
}

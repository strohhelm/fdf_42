/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:59 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 18:28:32 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
int	ft_absolute(int a, int b)
{
	int	nb;

	nb = a - b;
	return((nb >= 0) * nb + (nb < 0) * -1 * nb);
}

int	calc_distance(int h, int w)
{
	int	dist;

	dist = 0;
	if ( w > 500 || h > 500)
		ft_exit();
	if (h + w <= 30)
		dist = 50;
	else if (h + w <= 100)
		dist = 20;
	else if (h + w <= 250)
		dist = 10;
	else if (h + w <= 500)
		dist = 6;
	else if (h + w <= 1000)
		dist = 3;
	return (dist);
}

int	get_value_range(t_grid ***grid)
{
	int	min;
	int	max;
	int	i;
	int	j;
	
	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j]->value < min)
				min = grid[i][j]->value;
			else if (grid[i][j]->value > max)
				max = grid[i][j]->value;
			j++;
		}
		i++;
	}
	return (ft_absolute(max, min));
}
int	count_max_width(char *argv)
{
	int		i;
	int		fd;
	int		max;
	char	*line;
	char	**tmp;
	
	max = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit ();
	line = get_next_line(fd);
	if (!line)
		ft_exit();
	while (line)
	{
		tmp = ft_split(line, ' ');
		i = arr_len((void **)tmp);
		if (i > max)
			max = i;
		ft_free_2D_arr((void *)tmp);
		line = get_next_line(fd);

	}
	close(fd);
	return (max);
}
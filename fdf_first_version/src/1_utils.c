/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:08:53 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/27 18:38:54 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void ft_exit(void)
{
	ft_printf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	free_grid(t_grid ***arr, uint32_t h, uint32_t w)
{
	uint32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
			free(arr[i][j++]);
		free(arr[i]);
		i++;
	}
}

void ft_free_2D_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

int	arr_len(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	count_lines(char *argv)
{
	int		i;
	int		fd;
	int		bytes_read;
	char	buffer[21];
	int		count;

	count = 0;
	buffer[20] = '\0';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit ();
	bytes_read = read(fd, buffer, 20);
	if (!bytes_read)
		ft_exit ();
	while (bytes_read)
	{
		i = 0;
		while (i < 21)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		bytes_read = read(fd, buffer, 20);
	}
	close(fd);
	return (count);
}

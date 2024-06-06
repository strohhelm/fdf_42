/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:08:53 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/04 21:34:41 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_exit(char *msg)
{
	int	i;

	i = STDERR_FILENO;
	ft_printf(i, "ERROR: %s \nMLX: %s\n", msg, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	free_grid(t_point ***arr, uint32_t h, uint32_t w)
{
	uint32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			free(arr[i][j]);
			arr[i][j] = NULL;
			j++;
		}
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	ft_free_two_d_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	arr_len(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	count_lines(char *argv, int *count)
{
	int		i;
	int		fd;
	int		bt;
	char	buf[21];

	*count = 0;
	buf[20] = '\0';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit("file not found");
	bt = read(fd, buf, 20);
	if (bt < 0)
		ft_exit("could not read file");
	while (bt)
	{
		i = 0;
		while (i < bt)
		{
			if (buf[i] == 10 || (bt < 20 && i == bt - 1 && buf[bt - 1] != 10))
				*count += 1;
			i++;
		}
		bt = read(fd, buf, 20);
	}
	close(fd);
}

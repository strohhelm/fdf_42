/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:57:19 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 16:06:21 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static char	*jump_spaces(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ' )
	{
		str++;
	}
	return (str);
}

static int	ft_detect_sign(char s)
{
	if (s == '-')
		return (-1);
	if (s == '+')
		return (1);
	else
		return (0);
}

long	get_hex_nb(const char *str)
{
	char			*arr;
	int				i;
	unsigned int	value;
	int				tmp;

	arr = "0123456789abcdef";
	i = 0;
	value = 0;
	while (ft_strchr(arr, str[i]))
		i++;
	i--;
	while (i > 1)
	{
		tmp = ft_strchr(arr, *str) - arr;
		value += tmp;
		value *= 16;
		i--;
		str++;
	}
	value += ft_strchr(arr, *str) - arr;
	return (value);
}

long	ft_atol(const char *str)
{
	char	sign;
	char	*sp;
	long	value;

	sp = (char *)str;
	value = 0;
	sign = 0;
	sp = jump_spaces(sp);
	sign = ft_detect_sign(*sp);
	if (str[0] == '0' && str[1] == 'x')
		return (get_hex_nb(&str[2]));
	if (sign != 0)
		sp++;
	if (sign == 0)
		sign = 1;
	while (*sp >= '0' && *sp <= '9')
	{
		value = value * 10;
		value = value + sign * (*sp - '0');
		sp++;
	}
	return (value);
}

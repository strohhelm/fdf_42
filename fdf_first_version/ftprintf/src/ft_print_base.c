/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:15:03 by pstrohal          #+#    #+#             */
/*   Updated: 2024/04/24 16:40:58 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_base(t_count_list *plist, char chr, int base)
{
	unsigned int	num;
	unsigned int	rem;
	char			temp[sizeof(char) * 20];
	int				i;

	num = va_arg(plist->arg, unsigned int);
	rem = 0;
	i = 0;
	if (!num)
		ft_write("0", 1, plist);
	while (num > 0 && plist->error == 0)
	{
		rem = num - (num / base) * base;
		num /= base;
		temp[i++] = plist->hexarr[rem];
	}
	temp[i--] = '\0';
	while (i >= 0 && plist->error == 0)
	{
		if ('a' <= temp[i] && temp[i] <= 'z' && chr == 'X')
			temp[i] -= 32;
		ft_write(&temp[i--], 1, plist);
	}
	return ;
}

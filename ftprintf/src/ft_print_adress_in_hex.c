/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_in_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:06:55 by pstrohal          #+#    #+#             */
/*   Updated: 2024/04/24 16:41:21 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_adress_in_hex(t_count_list *plist)
{
	unsigned long	pa;
	unsigned int	rem;
	char			temp[sizeof(char) * 20];
	int				i;

	pa = (unsigned long)va_arg(plist->arg, void *);
	rem = 0;
	i = 0;
	if (!pa)
		temp[i++] = '0';
	while (pa > 0 && plist->error == 0)
	{
		rem = pa - (pa / 16) * 16;
		pa /= 16;
		temp[i++] = plist->hexarr[rem];
	}
	temp[i++] = 'x';
	temp[i] = '0';
	while (i >= 0 && plist->error == 0)
		ft_write(&temp[i--], 1, plist);
	return ;
}

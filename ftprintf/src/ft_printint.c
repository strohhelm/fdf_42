/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:11:11 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/08 12:30:20 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printint(t_count_list *plist)
{
	long				n;

	n = va_arg(plist->arg, int);
	if (n < -2147483648 || n > 2147483647)
		return ;
	if (n == -2147483648)
	{
		ft_write("-2147483648", 11, plist);
		return ;
	}
	if (n < 0)
	{
		ft_write("-", 1, plist);
		n *= -1;
	}
	ft_printnbr(n, plist);
	return ;
}

void	ft_printnbr(int n, t_count_list *plist)
{
	unsigned int	rem;
	char			temp[sizeof(char) * 13];
	int				i;

	rem = 0;
	i = 0;
	if (!n)
		ft_write("0", 1, plist);
	while (n > 0 && plist->error == 0)
	{
		rem = n - (n / 10) * 10;
		n /= 10;
		temp[i++] = plist->hexarr[rem];
	}
	temp[i--] = '\0';
	while (i >= 0 && plist->error == 0)
	{
		ft_write(&temp[i--], 1, plist);
	}
	return ;
}

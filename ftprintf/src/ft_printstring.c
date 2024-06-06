/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:03:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/04/24 16:44:41 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printstr(t_count_list *plist)
{
	char	*str;

	str = va_arg(plist->arg, char *);
	if (!str)
	{
		ft_write("(null)", 6, plist);
		return ;
	}
	while (*str && plist->error == 0)
	{
		ft_write (str, 1, plist);
		str++;
	}
	return ;
}

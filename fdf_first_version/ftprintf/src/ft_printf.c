/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:30:55 by pstrohal          #+#    #+#             */
/*   Updated: 2024/05/07 10:50:56 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	check_write_arg(char chr, t_count_list *plist)
{
	char	c;

	if (chr == '%')
		ft_write (&chr, 1, plist);
	else if (chr == 'c')
	{
		c = (char)(va_arg(plist->arg, int));
		ft_write (&c, 1, plist);
	}
	else if (chr == 's')
		ft_printstr(plist);
	else if (chr == 'p')
		ft_print_adress_in_hex(plist);
	else if (chr == 'd' || chr == 'i')
		ft_printint(plist);
	else if (chr == 'u')
		ft_print_base(plist, chr, 10);
	else if (chr == 'x' || chr == 'X')
		ft_print_base(plist, chr, 16);
	return ;
}

int	ft_printf(int fd, const char *str, ...)
{
	t_count_list	plist;

	va_start(plist.arg, str);
	plist.count = 0;
	plist.error = 0;
	plist.hexarr = "0123456789abcdef\0";
	plist.fd = fd;
	while (*str && plist.error == 0)
	{
		if (*str == '%')
		{
			check_write_arg(*(str++ + 1), &plist);
			if (plist.error < 0)
				return (-1);
		}
		else
			ft_write(str, 1, &plist);
		str++;
	}
	va_end(plist.arg);
	if (!(plist.error == 0))
		return (plist.error);
	return (plist.count);
}

// int	main(void)
// {
// 	int				p;
// 	char			*f;
// 	unsigned int	h;

// 	p = 65;
// 	f = "-1";
// 	h = 6843512;
// 	printf("%d\n", ft_printf(" NULL %p NULL ", f));
// 	   printf("%d\n", printf(" NULL %p NULL ", f));
// }
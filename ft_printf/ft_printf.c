/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:29:10 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:11:47 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(va_list args, const char c, int *n)
{
	unsigned long long	ptr;

	if (c == 'c')
		*n += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*n += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		*n += ft_putstr("0x");
		*n += ft_putptr(ptr, 0);
	}
	else if (c == 'd' || c == 'i')
		*n += ft_putnbr(va_arg(args, int), 1);
	else if (c == 'u')
		*n += ft_putnbr_s(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		*n += ft_hex(va_arg(args, unsigned int), c, 1);
	else if (c == '%')
		*n += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		n;

	n = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_type(args, str[++i], &n);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			n++;
		}
	}
	va_end(args);
	return (n);
}

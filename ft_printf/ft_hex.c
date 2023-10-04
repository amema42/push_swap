/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:25:27 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:32:14 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, const char format, int i)
{
	if (n >= 16)
	{
		i++;
		i = ft_hex(n / 16, format, i);
	}
	if (format == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	if (format == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

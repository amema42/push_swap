/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:48:34 by amema             #+#    #+#             */
/*   Updated: 2023/10/03 14:15:18 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int i)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (nb < 0)
	{
		i++;
		ft_putchar('-');
		i = ft_putnbr(-nb, i);
	}
	else
	{
		if (nb > 9)
		{
			i++;
			i = ft_putnbr(nb / 10, i);
		}
		ft_putchar(nb % 10 + 48);
	}
	return (i);
}

int	ft_putnbr_s(unsigned int nb, int i)
{
	if (nb > 9)
	{
		i++;
		i = ft_putnbr_s(nb / 10, i);
	}
	ft_putchar(nb % 10 + 48);
	return (i);
}

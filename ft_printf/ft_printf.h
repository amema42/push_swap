/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:05:51 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:24:53 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_type(va_list args, const char c, int *nchar);
int		ft_hex(unsigned int nb, const char format, int i);
int		ft_putnbr(int nb, int i);
int		ft_putnbr_s(unsigned int nb, int i);
int		ft_putptr(unsigned long long ptr, int i);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strln(const char *str);

#endif

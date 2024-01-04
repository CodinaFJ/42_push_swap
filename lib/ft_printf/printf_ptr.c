/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:46:45 by jcodina-          #+#    #+#             */
/*   Updated: 2023/10/24 19:40:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_reverse_digits(int i, char *base, int *digits)
{
	int	size;

	size = 0;
	while (i > 0)
	{
		size += write(1, &base[digits[32 - i]], 1);
		i--;
	}
	return (size);
}

static int	ft_putptrlen(unsigned long nbr, char *base)
{
	int	i;
	int	size;
	int	digits[32];
	int	len_base;

	i = 0;
	size = 0;
	len_base = ft_strlen(base);
	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	while (nbr > 0)
	{
		digits[31 - i] = nbr % len_base;
		nbr = nbr / len_base;
		i++;
	}
	size += ft_print_reverse_digits(i, base, digits);
	return (size);
}

int	printf_ptr(unsigned long var)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_putptrlen((unsigned long)var, "0123456789abcdef");
	return (len);
}

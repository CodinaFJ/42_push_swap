/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:53 by jcodina-          #+#    #+#             */
/*   Updated: 2023/10/21 11:25:11 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_variable(char vars_id, va_list valist)
{
	int	size;

	size = 0;
	if (vars_id == 'c')
		size = printf_char(va_arg(valist, int));
	else if (vars_id == 's')
		size = printf_str(va_arg(valist, char *));
	else if (vars_id == 'u')
		size = printf_unbr(va_arg(valist, unsigned int));
	else if (vars_id == 'i' || vars_id == 'd')
		size = printf_nbr(va_arg(valist, int));
	else if (vars_id == 'p')
		size = printf_ptr(va_arg(valist, unsigned long));
	else if (vars_id == 'x')
		size = printf_hex_low(va_arg(valist, int));
	else if (vars_id == 'X')
		size = printf_hex_upp(va_arg(valist, int));
	else if (vars_id == '%')
		size = write(1, "%", 1);
	else
		ft_putstr_fd("\nERROR VAR\n", 0);
	return (size);
}

/**
 * putstr limited by a character
 * @param str string to print
 * @param limiter limiter character
 * @return number of printed characters
 */
int	ft_putstr_limited(const char *str, char limiter)
{
	int	j;

	j = 0;
	while (str[j] && str[j] != limiter)
		j++;
	write(1, str, j);
	return (j);
}

int	ft_printf(const char *input, ...)
{
	va_list	valist;
	int		i;
	int		total_size;
	int		printed_size;

	i = 0;
	total_size = 0;
	va_start(valist, input);
	while (input[i])
	{
		printed_size = ft_putstr_limited(input + i, '%');
		i += printed_size;
		total_size += printed_size;
		if (!input[i])
			break ;
		i++;
		total_size += print_variable(input[i], valist);
		i++;
	}
	va_end(valist);
	return (total_size);
}

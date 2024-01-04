/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:31 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/03 09:07:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Transforms number nbr to hexadecimal and sends it to standard output.
 * @param nbr Number to transform and print.
 * @param hex_type LOWER_HEX to print in lowercase. UPPER_HEX to print in 
 * uppercase.
 * @return Number of printed characters.
 */
int	ft_putnbrlen_hex(long long nbr, int hex_type)
{
	int	size;

	if (nbr < 0)
		nbr = nbr + LONG_MAX + 1;
	if (hex_type == LOW)
		size = ft_putnbrlen_base(nbr, "0123456789abcdef");
	else if (hex_type == HIGH)
		size = ft_putnbrlen_base(nbr, "0123456789ABCDEF");
	else
		return (ft_putnbrlen_hex(nbr, LOW));
	return (size);
}

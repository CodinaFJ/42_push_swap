/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:31 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/03 09:19:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

static int	ft_correct_nbr(long long *nbr)
{
	int	size;

	size = 0;
	if (*nbr < 0)
	{
		*nbr = -*nbr;
		size += write(1, "-", 1);
	}
	else if (*nbr == 0)
	{
		size += write(1, "0", 1);
	}
	return (size);
}

/**
 * Error control for a given base
*/
static int	ft_correct_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (*(base + j) != '\0')
		{
			if (i != j && *(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * Transforms number nbr to given base and sends it to standard output.
 * @param nbr Number to transform and print.
 * @param base String containing the desired base.
 */
void	ft_putnbr_base(long long nbr, char *base)
{
	int	i;
	int	digits[32];
	int	len_base;

	i = 0;
	len_base = ft_strlen(base);
	if (ft_correct_base(base) == 0)
		return ;
	ft_correct_nbr(&nbr);
	while (nbr > 0)
	{
		digits[31 - i] = nbr % len_base;
		nbr = nbr / len_base;
		i++;
	}
	ft_print_reverse_digits(i, base, digits);
}

/**
 * Transforms number nbr to given base and sends it to standard output.
 * @param nbr Number to transform and print.
 * @param base String containing the desired base.
 * @return number of printed characters.
 */
int	ft_putnbrlen_base(long long nbr, char *base)
{
	int	i;
	int	size;
	int	digits[32];
	int	len_base;

	i = 0;
	size = 0;
	len_base = ft_strlen(base);
	if (ft_correct_base(base) == 0)
		return (0);
	size += ft_correct_nbr(&nbr);
	while (nbr > 0)
	{
		digits[31 - i] = nbr % len_base;
		nbr = nbr / len_base;
		i++;
	}
	size += ft_print_reverse_digits(i, base, digits);
	return (size);
}

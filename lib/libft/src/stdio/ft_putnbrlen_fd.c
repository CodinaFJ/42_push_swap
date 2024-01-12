/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:31 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:27 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	input_control(long nb, int fd, int *neg)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		*neg = -1;
	}
	else if (nb == 0)
	{
		write(fd, "0", 1);
		return (-1);
	}
	return (0);
}

/**
 * Sends number nb to file descriptor fd.
 * @param nb Number to send.
 * @param fd File descriptor to send number.
 * @return number of printed characters
 */
int	ft_putnbrlen_fd(long nb, int fd)
{
	char	number[10];
	long	looped_nb;
	int		index;
	int		neg;

	index = 0;
	neg = 1;
	if (input_control(nb, fd, &neg) == -1)
		return (1);
	looped_nb = nb;
	while (looped_nb != 0)
	{
		number[9 - index] = '0' + (looped_nb * neg) % 10;
		looped_nb = looped_nb / 10;
		index++;
	}
	write(fd, &number[9 - index + 1], index);
	if (neg == -1)
		return (index + 1);
	else
		return (index);
}

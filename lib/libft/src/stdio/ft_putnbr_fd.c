/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:31 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:07 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Sends number nb to file descriptor fd.
 * @param nb Number to send.
 * @param fd File descriptor to send number.
 */
void	ft_putnbr_fd(int nb, int fd)
{
	char	number[10];
	int		looped_nb;
	int		index;
	int		neg;

	index = 0;
	neg = 1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		neg = -1;
	}
	else if (nb == 0)
		write(fd, "0", 1);
	looped_nb = nb;
	while (looped_nb != 0)
	{
		number[9 - index] = '0' + (looped_nb * neg) % 10;
		looped_nb = looped_nb / 10;
		index++;
	}
	if (nb == -2147483648)
		number[9] = '8';
	write (fd, &number[9 - index + 1], index);
}

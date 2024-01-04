/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:40:46 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:06 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Sends character c to file descriptor fd.
 * @param c Character to send.
 * @param fd File descriptor to send character.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:10:21 by jcodina-          #+#    #+#             */
/*   Updated: 2023/10/24 19:40:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_nbr(int var)
{
	return (ft_putnbrlen_fd(var, 1));
}

int	printf_unbr(unsigned int var)
{
	char	*str;
	int		len;

	str = ft_uitoa(var);
	len = ft_putstrlen_fd(str, 1);
	free(str);
	return (len);
}

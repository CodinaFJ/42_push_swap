/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:15:25 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/11 19:32:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_abs_l(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

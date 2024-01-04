/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:27:03 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Returns the min value of two int variables.
 */
int	ft_min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

long long	ft_minl(long long n1, long long n2)
{
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

/**
 * Returns the max value of two int variables.
 */
int	ft_max(int n1, int n2)
{
	if (n1 < n2)
		return (n2);
	else
		return (n1);
}

long long	ft_maxl(long long n1, long long n2)
{
	if (n1 < n2)
		return (n2);
	else
		return (n1);
}

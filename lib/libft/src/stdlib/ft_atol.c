/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 15:20:10 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long	ft_atol(const char *nptr)
{
	size_t	        i;
	char	        neg;
	long long		num;

	i = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		neg = *(nptr + i);
		i++;
	}
	while (ft_isdigit((int)*(nptr + i)))
	{
		num = (num * 10) + (int)(*(nptr + i) - '0');
		i++;
	}
	if (neg == '-')
		return (-num);
	return (num);
}
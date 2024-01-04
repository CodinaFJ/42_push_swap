/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:04:37 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Converts the initial portion of the string pointed to by str 
 * to int. Spaces at the beginning of string are ignored.
 * Takes into consideration negative numbers
 * @param nptr string to translate to int
 * @return int result of the conversion
*/
int	ft_atoi(const char *nptr)
{
	size_t	i;
	char	neg;
	int		num;

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

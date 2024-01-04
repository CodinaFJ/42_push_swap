/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:24 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:10 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Compares strings s1 and s2 one byte at a time.
 * @param s1 string 1.
 * @param s2 string 2.
 * @return 0 if the two strings are identical, otherwise returns the difference
 * between the first two differing bytes.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return ((int)(*(s1 + i)) - (int)(*(s2 + i)));
		i++;
	}
	return ((int)(*(s1 + i)) - (int)(*(s2 + i)));
}

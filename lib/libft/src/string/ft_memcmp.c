/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:24 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Compares memory areas s1 and s2 one byte at a time.
 * Compares for n bytes long.
 * @param s1 memory area 1.
 * @param s2 memory area 2.
 * @param n number of bytes to compare.
 * @return 0 if the two areas are identical, otherwise returns the difference
 * between the first two differing bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return ((int)(*((unsigned char *)(s1 + i)))
				- (int)(*((unsigned char *)(s2 + i))));
		i++;
	}
	return (0);
}

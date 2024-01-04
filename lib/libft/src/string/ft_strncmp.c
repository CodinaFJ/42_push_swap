/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:10:26 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:19 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Compares strings s1 and s2 one byte at a time.
 * Compares for n bytes long.
 * @param s1 string 1.
 * @param s2 string 2.
 * @param n number of bytes to compare.
 * @return 0 if the two strings are identical, otherwise returns the difference
 * between the first two differing bytes.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n - 1)
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char)(*(s1 + i)) - (unsigned char)(*(s2 + i)));
		i++;
	}
	return ((unsigned char)(*(s1 + i)) - (unsigned char)(*(s2 + i)));
}

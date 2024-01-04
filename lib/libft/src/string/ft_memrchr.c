/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:42:58 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Locates last occurrence of c in memory area s within n bytes.
 * @param s searched memory area
 * @param c character to search
 * @param n bytes to cover in the search
 * @return pointer to byte located, or NULL if there is no occurrence
 */
void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[n - 1 - i] == c)
			return ((void *) s + n - 1 - i);
		i++;
	}
	return (NULL);
}

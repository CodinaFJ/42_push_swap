/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:15 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Locates first occurrence of c in memory area s within n bytes.
 * @param s searched memory area.
 * @param c character to search.
 * @param n bytes to cover in the search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*((unsigned char *)s + i)) == (unsigned char)c)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}

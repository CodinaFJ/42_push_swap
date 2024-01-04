/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:05 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:20 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Copy n bytes from memory area src to memory area dest using ft_memcpy().
 * If the character c occurs in the memory area src + n the copy stops 
 * and a pointer to the byte after the copy of c in the string dst is returned.
 * Otherwise, n bytes are copied, and a NULL pointer is returned.
 * @param dest memory area to fill.
 * @param src memory area to be copied.
 * @param c character that stops copy.
 * @param n number of bytes to copy.
 * @return pointer to the byte after the copy of c. If c does not occur,
 * return NULL.
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*mem_c;

	mem_c = ft_memchr(src, c, n);
	if (mem_c != NULL)
		n = ((unsigned char *) mem_c - (unsigned char *) src);
	ft_memcpy(dest, src, n);
	if (mem_c == NULL)
		return (NULL);
	else
		return ((void *)(((unsigned char *)mem_c) + 1));
}

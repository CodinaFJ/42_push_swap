/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:43 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Copies n bytes from memory area src to memory area dest.
 * The areas may overlap; the copy is always done in a non-destructive manner.
 * @param dest memory area to fill.
 * @param src memory area to be copied.
 * @param n number of bytes to copy.
 * @return original value of dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	if (src >= dest && src <= dest + n)
	{
		while (i < n)
		{
			*((unsigned char *) dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else if (src <= dest && dest <= src + n)
	{
		while (i < n)
		{
			*((unsigned char *) dest + (n - 1 - i))
				= *((unsigned char *)src + (n - 1 - i));
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

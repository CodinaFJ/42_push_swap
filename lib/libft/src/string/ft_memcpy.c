/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:32 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:20 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Copy n bytes from memory area src to memory area dest.
 * If dest and src overlap ft_memmove() is used instead.
 * @param dest memory area to fill.
 * @param src memory area to be copied.
 * @param n number of bytes to copy.
 * @return original value of dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (NULL);
	if ((src >= dest && src <= dest + n)
		|| (src <= dest && dest <= src + n))
	{
		if (ft_memmove(dest, src, n) == NULL)
			return (NULL);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *) dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}

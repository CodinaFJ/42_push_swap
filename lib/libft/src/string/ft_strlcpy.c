/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:59 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Copies the string src to the string dest.
 * String dest must have enough space to hold the result.
 * Grants null termination. Safer than strcpy and strncpy.
 * @param dest string to fill.
 * @param src string to copy.
 * @param size buffer size of dest.
 * @return Total length of the string tried to create.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_return;

	i = 0;
	size_return = 0;
	while (src[size_return] != 0)
		size_return++;
	if (size == 0)
		return (size_return);
	while (*(src + i) != 0 && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (size_return);
}

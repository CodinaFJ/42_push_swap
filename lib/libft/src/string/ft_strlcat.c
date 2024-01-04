/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:53 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:14 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Appends the string src to the end of the string dest.
 * String dest must have enough space to hold the result.
 * Grants null termination. Safer than strcat and strncat.
 * @param dest string to fill.
 * @param src string to append.
 * @param size buffer size of dest.
 * @return Total length of the string tried to create
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	while (dest[i])
		i++;
	if (size <= i)
		return (size + ft_strlen(src));
	dest_len = i;
	while (src[i - dest_len] && i < size)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (size == i)
		dest[size - 1] = '\0';
	else
		dest[i] = '\0';
	if (size < dest_len)
		return (size + ft_strlen(src));
	return (dest_len + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:26:57 by jcodina-          #+#    #+#             */
/*   Updated: 2024/03/03 20:04:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Appends the string src to the end of the string dest.
 * String dest must have enough space to hold the result.
 * Grants null termination. Safer than strcat and strncat.
 * @param dest string to fill.
 * @param src string to append.
 * @param size buffer size of dest.
 * @return Total length of the string tried to create
 */
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (size == 0 || !src || *src == 0)
		return (0);
	src_len = ft_strlen_gnl((char *)src);
	dest_len = ft_strlen_gnl(dest);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
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
		return (size + src_len);
	return (dest_len + src_len);
}

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * Allocates a string where copies a substring, which strats at index start
 * and has a max length of len. If string s ends before len can be achived
 * copy stops.
 * @param s source string.
 * @param start index where to start the substring.
 * @param len max length of the substring.
 * @return Pointer to allocated substring. NULL if allocation fails.
 */
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	total_len;
	size_t	size;
	char	*str;

	str = NULL;
	total_len = ft_strlen_gnl((char *)s);
	if (total_len - (size_t) start > len)
		size = len;
	else
		size = total_len - (size_t) start;
	if (start > total_len)
		return ((char *)ft_calloc_gnl(1, 1));
	str = (char *)ft_calloc_gnl(1, size + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcat_gnl(str, s + start, size + 1);
	return (str);
}

/**
 * Contiguously allocates enough space for count objects that are size bytes
 * of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 * @param count number of objects.
 * @param size bytes of each objects.
 * @return Pointer to alllocated memory. NULL is allocation fails.
 */
void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	i = 0;
	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (i < count * size)
	{
		*(((unsigned char *)s) + i) = '\0';
		i++;
	}
	return (s);
}

/**
 * Allocates a string where the result of the concatenation of s1 and s2
 * is copied - memory liberated after join.
 * @param s1 string 1.
 * @param s2 string 2.
 * @return Allocated string. NULL if allocation fails.
 */
char	*ft_strjoin_free_gnl(char **s1, char **s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen_gnl(*s1) + ft_strlen_gnl(*s2);
	str = (char *)ft_calloc_gnl(1, size + 1);
	if (!str)
	{
		free(*s1);
		free(*s2);
		return (NULL);
	}
	ft_strlcat_gnl(str, *s1, size + 1);
	ft_strlcat_gnl(str, *s2, size + 1);
	free(*s1);
	free(*s2);
	*s1 = NULL;
	*s2 = NULL;
	return (str);
}

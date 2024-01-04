/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:10:50 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:19 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Locates the first occurrence (in no more than len bytes of haystack)
 * of the null-terminated string needle in the null-terminated string haystack.
 * @param haystack string searched in.
 * @param needle string searched for.
 * @param len limit of searched characters searched in haystack.
 * @return If needle is empty, haystack is returned.
 * If needle occurs nowhere in haystack, NULL is returned.
 * Otherwise a pointer to the first occurrence is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	char	*s;
	size_t	n_len;

	if (*needle == '\0')
		return ((char *) haystack);
	if (len < 0)
		len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	s = (char *) haystack;
	s = ft_strchr(haystack, (int)*needle);
	while (s != NULL && ((s + n_len) - haystack) <= (long) len)
	{
		if (ft_memcmp(s, needle, n_len) == 0)
			return (s);
		s = ft_strchr(s + 1, (int)*needle);
	}
	return (NULL);
}

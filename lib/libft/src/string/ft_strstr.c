/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:12 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Locates the first occurrence of the null-terminated string needle 
 * in the null-terminated string haystack.
 * @param haystack string searched in.
 * @param needle string searched for.
 * @return If needle is empty, haystack is returned.
 * If needle occurs nowhere in haystack, NULL is returned.
 * Otherwise a pointer to the first occurrence is returned.
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s;
	int		n_len;

	if (*needle == '\0')
		return ((char *) haystack);
	n_len = ft_strlen(needle);
	s = (char *) haystack;
	while (s != NULL)
	{
		s = ft_strchr(haystack, (int) *needle);
		if (ft_memcmp(s, needle, n_len) == 0)
			return (s);
	}
	return (s);
}

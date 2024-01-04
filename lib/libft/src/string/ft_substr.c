/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:23:09 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:22 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Allocates a string where copies a substring, which strats at index start
 * and has a max length of len. If string s ends before len can be achived
 * copy stops.
 * @param s source string.
 * @param start index where to start the substring.
 * @param len max length of the substring.
 * @return Pointer to allocated substring. NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	size;
	char	*str;

	slen = ft_strlen(s);
	size = ft_minl(slen - (size_t) start, len);
	if (start > slen)
	{
		str = malloc(1);
		if (str == NULL)
		{
			free(str);
			return (NULL);
		}
		*str = '\0';
		return (str);
	}
	str = malloc(size + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}

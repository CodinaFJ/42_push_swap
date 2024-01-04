/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:09:04 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:18 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Allocates a string where the result of the concatenation of s1 and s2
 * is copied.
 * @param s1 string 1.
 * @param s2 string 2.
 * @return Allocated string. NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s1, size + 1);
	ft_strlcat(str, s2, size + 1);
	return (str);
}

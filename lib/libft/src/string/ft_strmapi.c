/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:22:30 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:27 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Applies f function to each character of string s.
 * Generates a new allocated string as result of the application of f
 * to the whole string s.
 * @param s String to be used on f.
 * @param f Function that evaluates all characters of s.
 * Takes as parameters the character to be evaluated and its index.
 * @return String allocated with the result. NUll is allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	str_len;

	i = 0;
	str_len = ft_strlen(s);
	str = malloc((str_len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (i < str_len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[str_len] = 0;
	return (str);
}

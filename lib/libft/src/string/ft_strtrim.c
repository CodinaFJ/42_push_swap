/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:26:02 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:33 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Calculates indexes that limit the trimmed result to be copied.
 */
static void	get_trim_indexes(char const *s1, char const *set,
	int *i, int *j)
{
	if (!*s1)
	{
		*i = 0;
		*j = -1;
		return ;
	}
	else if (!set)
		return ;
	while (*i <= *j)
	{
		if (!ft_strchr(set, (int) s1[*i]) && !ft_strchr(set, (int) s1[*j]))
			return ;
		if (ft_strchr(set, (int) s1[*i]))
			(*i)++;
		if (ft_strchr(set, (int) s1[*j]))
			(*j)--;
	}
}

/**
 * Removes characters in string set from beginning and end of the string s1.
 * Resulting string is returned i a new allocated string.
 * @param s1 String to be trimmed.
 * @param set Characters to remove.
 * @return Allocated trimmed string. NULL is allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	get_trim_indexes(s1, set, &i, &j);
	if (j < i)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc((j - i + 2) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s1 + i, j - i + 2);
	return (str);
}

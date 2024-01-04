/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:15:12 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_size_strs(char const *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0 && c != 0)
	{
		if (str[i] != c)
		{
			size++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (c == 0 || (size == 0 && !ft_strchr(str, c)))
		return (1);
	else if (size == 0)
		return (0);
	return (size);
}

static char	*get_split_word(char const *str, char c)
{
	int		wrd_len;
	char	*res;

	wrd_len = 0;
	while (str[wrd_len] != c && str[wrd_len])
		wrd_len++;
	res = (char *)malloc((wrd_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str, wrd_len + 1);
	return (res);
}

static char	**protect_input(char const *str, char c)
{
	char	**strs;
	int		str_len;

	if (*str == '\0')
	{
		strs = malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	else if (c == '\0')
	{
		strs = malloc(sizeof(char *) * 2);
		if (!strs)
			return (NULL);
		str_len = ft_strlen(str);
		strs[0] = malloc(str_len + 1);
		if (!strs[0])
			return (free_darray((void **)strs, 1));
		ft_strlcpy(strs[0], str, str_len + 1);
		strs[1] = NULL;
		return (strs);
	}
	return (NULL);
}

static char	**split_loop(char **strs, char const *str, char c)
{
	int	i;
	int	j;
	int	str_len;

	i = 0;
	j = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		if (str[i] != c)
		{
			strs[j] = get_split_word(str + i, c);
			if (strs[j] == NULL)
				return (free_darray((void **)strs, j + 1));
			j++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		while (str[i] == c)
			i++;
	}
	return (strs);
}

/**
* Fills an array of strings with the results of dividing the string str
* using the char c as separator. Array returned is null terminated.
* @param str string to divide
* @param c separator char
* @return null terminated array of strings
*/
char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		strs_size;

	if (*str == '\0' || c == '\0')
		return (protect_input(str, c));
	strs_size = get_size_strs(str, c);
	strs = (char **)malloc((strs_size + 1) * sizeof(char *));
	if (strs == NULL)
		return (free_darray((void **)strs, 0));
	strs[strs_size] = NULL;
	strs = split_loop(strs, str, c);
	return (strs);
}

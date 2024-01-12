/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:25:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:58 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Locates first occurrence of c in NULL terminated matrix of strings.
 * Sets by reference the coordinates i and j.
 * @param strs NULL terminated matrix od strings.
 * @param c character to search.
 * @param i_out row of c in strs (undefined if no occurrence).
 * @param j_out col of c in strs (undefined if no occurrence).
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strschr(const char **strs, const char c, int *row_out, int *col_out)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == c)
			{
				*row_out = i;
				*col_out = j;
				return ((char *) &strs[i][j]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

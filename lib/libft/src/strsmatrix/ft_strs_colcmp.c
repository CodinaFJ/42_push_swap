/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_colcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:22:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:42 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two columns of a NULL terminated strings matrix one byte at a time.
*/
int	ft_strs_colcmp(char **strs, int col_a, int col_b)
{
	unsigned int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		if (strs[i][col_a] != strs[i][col_b])
		{
			return (strs[i][col_a] - strs[i][col_b]);
		}
		i++;
	}
	return (0);
}

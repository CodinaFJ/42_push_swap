/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:15:21 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:57:14 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Empties and frees all strings in the strings matrix. Keeps allocation of
 * strs matrix.
*/
void	ft_strs_clear(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		if (strs[i] != NULL)
			free(strs[i]);
		strs[i] = NULL;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:24 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Used to protect double pointer array p form allocation error.
 * Liberates n arrays in p and p.
 * @param p Double pointer to liberate recursively.
 * @param n Number of arrays in p to free. 
 * @return NULL
 */
void	*free_darray(void **p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

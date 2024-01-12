/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:46:52 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:54 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Calculates the number of rows of a NULL terminated matrix of strings.
*/
unsigned int	ft_strs_rows(const char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

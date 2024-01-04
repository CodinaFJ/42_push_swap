/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_cols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:46:52 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 13:46:52 by jcodina-         ###   ########.fr       */
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
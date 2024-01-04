/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_rowcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:18:13 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 14:18:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two rows one byte at a time.
*/
int	ft_strs_rowcmp(char **strs, int row_a, int row_b)
{
	return (ft_strcmp(strs[row_a], strs[row_b]));
}
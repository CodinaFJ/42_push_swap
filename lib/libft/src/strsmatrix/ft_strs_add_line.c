/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_add_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:39:34 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Duplicates str and apends it to the NULL terminated matrix of strings strs.
 * Matrix of strings should have enough allocated space.
 * @param str source string.
 * @param strs strings matrix where str is being appended.
 * @return Pointer to added string. NULL if allocation fails.
 */
char	*ft_strs_add_line(const char *str, char **strs)
{
	unsigned int	i;

	i = ft_strs_cols((const char **) strs);
	strs[i] = ft_strdup(str);
	strs[i + 1] = NULL;
	return (strs[i]);
}

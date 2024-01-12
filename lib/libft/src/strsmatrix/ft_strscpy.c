/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:47:04 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:57:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copy NULL terminated matrix of strings src to dest.
 * Dest must already have enough allocated space to copy src.
 * Makes dest NULL terminated.
 */
void	ft_strscpy(char **dst, const char **src)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
	{
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	dst[i] = NULL;
}

/**
 * Copy NULL terminated matrix of strings src to dest until a row.
 * Dest must already have enough allocated space to copy src.
 * Makes dest NULL terminated.
 */
void	ft_strsncpy(char **dst, char **src, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < row)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:34:24 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:57 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Blank character test.
 * Any of: '\t' ' '
*/
int	ft_isblank(int c)
{
	if ((unsigned char) c == ' ' || (unsigned char) c == '\t')
		return (1);
	return (0);
}

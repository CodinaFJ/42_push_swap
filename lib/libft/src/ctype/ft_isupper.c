/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:44 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Uppercase character test.
*/
int	ft_isupper(int c)
{
	if (c >= (int) 'A' && c <= (int) 'Z')
		return (1);
	return (0);
}

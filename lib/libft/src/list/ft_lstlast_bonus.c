/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:59:12 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Returns last node of list
 * @param lst Pointer to first node of the list.
 * @return Pointer to last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

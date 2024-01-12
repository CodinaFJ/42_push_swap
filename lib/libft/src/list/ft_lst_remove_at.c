/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:04:20 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:51:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Removes node in list at position index.
 * Returnes matched and removed node content.
 * Node matched in list is freed. Content from said node is not freed.
 * @param lst List where to remove node with content specified
 * @param index Content searched in lst to be removed.
 * @return pointer to content of the node removed. NULL if none is removed.
*/
void	*ft_lst_remove_at(t_list **lst, int index)
{
	void	*aux;
	int		i;
	t_list	*node;
	t_list	*node_prev;

	node_prev = NULL;
	node = *lst;
	i = 0;
	while (node != NULL)
	{
		if (i == index)
		{
			if (node_prev != NULL)
				node_prev->next = node->next;
			else
				*lst = node->next;
			aux = node->content;
			free(node);
			return (aux);
		}
		node_prev = node;
		node = node->next;
		i++;
	}
	return (NULL);
}

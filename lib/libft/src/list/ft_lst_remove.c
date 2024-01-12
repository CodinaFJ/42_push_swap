/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:04:20 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:51:00 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Removes node in list that makes the (*compare)(void *, void *) function
 * return 1.
 * Returnes matched and removed node content.
 * Node matched in list is freed. Content from said node is not freed.
 * @param lst List where to remove node with content specified
 * @param content Content searched in lst to be removed.
 * @param compare Function used to check if content is in list.
 * @return pointer to content of the node removed. NULL if none is removed.
*/
void	*ft_lst_remove(t_list **lst, void *content,
			int (*compare)(void *, void *))
{
	void	*aux;
	t_list	*node;
	t_list	*node_prev;

	node_prev = NULL;
	node = *lst;
	while (node != NULL)
	{
		if (compare(content, node->content))
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
	}
	return (NULL);
}

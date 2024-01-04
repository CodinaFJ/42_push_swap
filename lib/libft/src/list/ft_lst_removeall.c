/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_removeall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:23:05 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 15:23:05 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Removes all nodes in list that makes the (*compare)(void *, void *) function return 1.
 * Removed nodes and content are freed using del function.
 * @param lst List where to remove node with content specified
 * @param content Content searched in lst to be removed.
 * @param compare Function used to check if content is in list.
 * @param del Function used to free content from removed nodes.
*/
void	ft_lst_remove_all(t_list **lst, void *content, int (*compare)(void *, void *), void (*del)(void *))
{
	t_list	*node_prev;
	t_list	*node;

	node_prev = NULL;
	node = *lst;
	while (node != NULL)
	{
		if (compare(content, node->content))
		{
			if (node_prev != NULL)
				*lst = node->next;
			else
				node_prev->next = node->next;
			ft_lstdelone(node, del);
		}
		node_prev = node;
		node = node->next;
	}
}
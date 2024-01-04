/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:27:04 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:44 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Removes and liberates node lst and all consucutives.
 * @param lst Node where to start removing nodes.
 * @param del Function used to remove content of each node
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_next;

	node = *lst;
	while (node != NULL)
	{
		node_next = node->next;
		if (node != NULL && del != NULL)
		{
			(*del)(node->content);
			free(node);
		}
		node = node_next;
	}
	*lst = NULL;
}

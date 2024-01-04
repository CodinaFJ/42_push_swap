/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:49:21 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:42 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Iterates through list lst and applies function f to content of each node.
 * @param lst List to iterate through-
 * @param f Function to apply to the content of each node.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		(*f)(node->content);
		node = node->next;
	}
}

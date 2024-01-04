/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:54 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	*ft_free_lst(t_list *lst, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&lst, del);
	return (NULL);
}

/**
 * Iterates through list lst and applies function f to content of each node.
 * Returns list result of the application of function f to each node.
 * @param lst List to iterate through.
 * @param f Function to apply to each node.
 * @param del Function to delete content of nodes in list
 * @return List result of the application of function f to each node 
 * in list lst
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	void	*cont_aux;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	new_lst = NULL;
	while (lst)
	{
		cont_aux = f(lst->content);
		if (!cont_aux)
			return (ft_free_lst(new_lst, cont_aux, del));
		new_node = ft_lstnew(cont_aux);
		if (new_node == NULL)
			return (ft_free_lst(new_lst, cont_aux, del));
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}

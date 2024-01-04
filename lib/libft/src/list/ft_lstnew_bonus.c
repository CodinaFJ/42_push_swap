/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:38:14 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Allocates new t_list node. Fills content with argument and points
 * next to NULL.
 * @param content Variable to assign to content of t_list.
 * @return Allocated t_list node. NULL if allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_exists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:59:34 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 14:59:34 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Check if content is in list, using criteria of comparison given in function compare (void *, void *)
 * @return index if found. -1 if not found.
*/
int	ft_lst_exists(t_list *lst, void *content, int (*compare)(void *, void *))
{
	t_list	*node;
	int		i;

	node = lst;
	i = 0;
	while (node != NULL)
	{
		if (compare(content, node->content))
		{
			return (i);
		}
		node = node->next;
		i++;
	}
	return (-1);
}
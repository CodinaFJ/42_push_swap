/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dup.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:59:34 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 14:59:34 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Duplicate list.
 * @param lst_src list to duplicate.
 * @param dup function to duplicate content.
 * @return duplicated and allocated list.
*/
t_list	*ft_lst_dup(t_list *lst_src, void *(*dup)(void *))
{
	t_list	*lst_dst;

	lst_dst = ft_lstnew(dup(lst_src->content));
	lst_src = lst_src->next;
	while (lst_src != NULL)
	{
		ft_lstadd_back(&lst_dst, ft_lstnew(dup(lst_src->content)));
		lst_src = lst_src->next;
	}
	return (lst_dst);
}
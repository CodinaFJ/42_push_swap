/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_precomp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:01:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 15:11:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_3(t_stack_i *stack)
{
	if (stack_is_sorted(stack))
		return ;
	if (stack_cmp_str(stack, "0 2 1"))
		stack_execute_moves(stack, NULL, SORT_021);
	else if (stack_cmp_str(stack, "1 0 2"))
		stack_execute_moves(stack, NULL, SORT_102);
	else if (stack_cmp_str(stack, "1 2 0"))
		stack_execute_moves(stack, NULL, SORT_120);
	else if (stack_cmp_str(stack, "2 0 1"))
		stack_execute_moves(stack, NULL, SORT_201);
	else if (stack_cmp_str(stack, "2 1 0"))
		stack_execute_moves(stack, NULL, SORT_210);
}

void    sort_2(t_stack_i *stack)
{
	if (stack_is_sorted(stack))
		return ;
	stack_execute_move(stack, NULL, "sa");
}
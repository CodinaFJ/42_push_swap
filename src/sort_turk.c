/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:29:14 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:37:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_turk_phase1(t_stack_i *stack_a, t_stack_i *stack_b)
{
	size_t	index;

	if (stack_a->size <= 3)
		return ;
	push(stack_b, stack_a);
	if (stack_a->size > 3)
		push(stack_b, stack_a);
	while (stack_a->size > 3)
	{
		index = select_best_candidate(stack_a, stack_b);
		perform_min_moves(stack_a, stack_b, index - stack_a->bottom,
			stack_min_proxtonbr(stack_b,
				stack_a->array[index % stack_a->capacity]));
		stack_execute_move(stack_a, stack_b, "pb");
	}
}

static void	sort_turk_phase2(t_stack_i *stack_a, t_stack_i *stack_b)
{
	size_t	index;

	sort_3(stack_a);
	while (stack_b->size > 0)
	{
		index = select_best_candidate_back(stack_b, stack_a);
		perform_min_moves(
			stack_b,
			stack_a,
			index - stack_b->bottom,
			stack_max_proxtonbr(
				stack_a,
				stack_b->array[index % stack_b->capacity]));
		stack_execute_move(stack_a, stack_b, "pa");
	}
	if (stack_top(stack_a) > (long long) stack_a->capacity / 2)
		while (!stack_is_sorted(stack_a))
			stack_execute_move(stack_a, stack_b, "ra");
	else
		while (!stack_is_sorted(stack_a))
			stack_execute_move(stack_a, stack_b, "rra");
}

void	sort_turk(t_stack_i *stack_a, t_stack_i *stack_b)
{
	sort_turk_phase1(stack_a, stack_b);
	sort_turk_phase2(stack_a, stack_b);
}

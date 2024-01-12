/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_calc_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:48 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 16:49:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	calculate_cost(const t_stack_i *stack_a, const t_stack_i *stack_b,
			size_t index_a, size_t index_b)
{
	t_n_moves		moves;
	t_moves_combs	moves_combs;
	size_t			min_moves;

	moves.ra = stack_a->size - 1 - index_a;
	moves.rb = stack_b->size - 1 - index_b;
	moves.rra = 1 + index_a;
	moves.rrb = 1 + index_b;
	moves.rr = ft_minl(moves.ra, moves.rb);
	moves.rrr = ft_minl(moves.rra, moves.rrb);
	moves_combs.ra_rb = moves.rr + ft_abs_l(moves.ra - moves.rb);
	moves_combs.rra_rrb = moves.rrr + ft_abs_l(moves.rra - moves.rrb);
	moves_combs.ra_rrb = moves.ra + moves.rrb;
	moves_combs.rra_rb = moves.rra + moves.rb;
	min_moves = ft_minl(moves_combs.ra_rb,
			ft_minl(moves_combs.rra_rrb,
				ft_minl(moves_combs.ra_rrb, moves_combs.rra_rb)));
	return (min_moves);
}

size_t	select_best_candidate(const t_stack_i *stack_a,
			const t_stack_i *stack_b)
{
	size_t	i;
	size_t	aux;
	size_t	min_cost;
	size_t	min_idx;

	min_cost = LONG_MAX;
	i = 0;
	while (i < stack_a->size)
	{
		aux = calculate_cost(
				stack_a, stack_b,
				i,
				stack_min_proxtonbr(stack_b,
					stack_a->array[(stack_a->bottom + i) % stack_a->capacity]));
		if (aux < min_cost)
		{
			min_cost = aux;
			min_idx = stack_a->bottom + i;
		}
		i++;
	}
	return (min_idx);
}

size_t	select_best_candidate_back(const t_stack_i *stack_a,
			const t_stack_i *stack_b)
{
	size_t	i;
	size_t	aux;
	size_t	min_cost;
	size_t	max_idx;

	min_cost = LONG_MAX;
	i = 0;
	if (stack_a->size == 1)
		return (stack_a->bottom);
	while (i < stack_a->size)
	{
		aux = calculate_cost(stack_a, stack_b, i,
				stack_max_proxtonbr(stack_b,
					stack_a->array[(stack_a->bottom + i) % stack_a->capacity]));
		if (aux < min_cost)
		{
			min_cost = aux;
			max_idx = stack_a->bottom + i;
		}
		i++;
	}
	return (max_idx);
}

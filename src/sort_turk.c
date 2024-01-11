/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:29:14 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/11 21:40:50 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_execute_moves_rest(t_stack_i *stack_a, t_stack_i *stack_b, t_turk_moves moves_select, size_t move_a, size_t move_b)
{
	long long	diff;

	diff = ft_abs_l((long long) move_a - (long long) move_b);
	if (moves_select == RARB)
	{
		if (move_a > move_b)
				stack_execute_move_rep(stack_a, stack_b, "ra", diff);
		else
				stack_execute_move_rep(stack_a, stack_b, "rb", diff);
	}
	else if (moves_select == RRARRB)
	{
		if (move_a > move_b)
				stack_execute_move_rep(stack_a, stack_b, "rra", diff);
		else
				stack_execute_move_rep(stack_a, stack_b, "rrb", diff);
	}
}

void	execute_moves_comb(t_stack_i *stack_a, t_stack_i *stack_b, t_n_moves moves, t_turk_moves moves_select)
{
	if (moves_select == RARB)
	{
		stack_execute_move_rep(stack_a, stack_b, "rr", moves.rr);
		stack_execute_moves_rest(stack_a, stack_b, RARB, moves.ra, moves.rb);
	}
	else if (moves_select == RRARRB)
	{
		stack_execute_move_rep(stack_a, stack_b, "rrr", moves.rrr);
		stack_execute_moves_rest(stack_a, stack_b, RRARRB, moves.rra, moves.rrb);
	}
	else if (moves_select == RARRB)
	{
		stack_execute_move_rep(stack_a, stack_b, "ra", moves.ra);
		stack_execute_move_rep(stack_a, stack_b, "rrb", moves.rrb);
	}
	else if (moves_select == RRARB)
	{
		stack_execute_move_rep(stack_a, stack_b, "rra", moves.rra);
		stack_execute_move_rep(stack_a, stack_b, "rb", moves.rb);
	}
}

void	perform_min_moves(t_stack_i *stack_a, t_stack_i *stack_b, size_t index_a, size_t index_b)
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
	if (moves_combs.ra_rb  == min_moves)
		execute_moves_comb(stack_a, stack_b, moves, RARB);
	else if (moves_combs.rra_rrb  == min_moves)
		execute_moves_comb(stack_a, stack_b, moves, RRARRB);
	else if (moves_combs.ra_rrb  == min_moves)
		execute_moves_comb(stack_a, stack_b, moves, RARRB);
	else if (moves_combs.rra_rb  == min_moves)
		execute_moves_comb(stack_a, stack_b, moves, RRARB);
}

size_t	calculate_cost(t_stack_i *stack_a, t_stack_i *stack_b, size_t index_a, size_t index_b)
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
	//ft_printf("a[%d]->b[%d]: ra(%d), rb(%d), rra(%d), rrb(%d) -> min: %d\n", index_a, index_b, moves.ra, moves.rb, moves.rra, moves.rrb, min_moves);
	return (min_moves);
}

size_t	select_best_candidate(t_stack_i *stack_a, t_stack_i *stack_b)
{
	size_t	i;
	size_t	aux;
	size_t	min_cost;
	size_t	min_idx;

	min_cost = LONG_MAX;
	i = 0;
	while (i < stack_a->size)
	{
		aux = calculate_cost(stack_a, stack_b, i, stack_min_proxtonbr(stack_b, stack_a->array[(stack_a->bottom + i) % stack_a->capacity]));
		if (aux < min_cost)
		{
			min_cost = aux;
			min_idx = stack_a->bottom + i;
		}
		i++;
	}
	//ft_printf("The best candidate is index %d (%d) with a cost of %d\n", min_idx, stack_a->array[min_idx % stack_a->capacity], min_cost);
	return (min_idx);
}

size_t	select_best_candidate_back(t_stack_i *stack_a, t_stack_i *stack_b)
{
	size_t	i;
	size_t	aux;
	size_t	max_cost;
	size_t	max_idx;

	max_cost = 0;
	i = 0;
	while (i < stack_a->size)
	{
		aux = calculate_cost(stack_a, stack_b, i, stack_max_proxtonbr(stack_b, stack_a->array[(stack_a->bottom + i) % stack_a->capacity]));
		if (aux > max_cost)
		{
			max_cost = aux;
			max_idx = stack_a->bottom + i;
		}
		i++;
	}
	//ft_printf("The best candidate is index %d (%d) with a cost of %d\n", max_idx, stack_a->array[max_idx % stack_a->capacity], max_cost);
	return (max_idx);
}

void	sort_turk(t_stack_i *stack_a, t_stack_i *stack_b)
{
	size_t	index;

	push(stack_b, stack_a);
	push(stack_b, stack_a);
	while (stack_a->size > 3)
	{
		index = select_best_candidate(stack_a, stack_b);
		perform_min_moves(stack_a, stack_b, index - stack_a->bottom, stack_min_proxtonbr(stack_b, stack_a->array[index % stack_a->capacity]));
		push(stack_b, stack_a);
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
	{
		index = select_best_candidate_back(stack_b, stack_a);
		perform_min_moves(stack_b, stack_a, index - stack_b->bottom, stack_max_proxtonbr(stack_a, stack_b->array[index % stack_b->capacity]));
		push(stack_a, stack_b);
	}
	while (!stack_is_sorted(stack_a))
		rotate(stack_a);
	// stack_print(stack_a);
	// stack_print(stack_b);
}
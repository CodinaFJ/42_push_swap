/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:39:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 16:49:04 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	stack_execute_moves_rarb(t_stack_i *stack_a, t_stack_i *stack_b,
			size_t move_a, size_t move_b)
{
	long long	diff;

	diff = ft_abs_l((long long) move_a - (long long) move_b);
	if (move_a > move_b)
		stack_execute_move_rep(stack_a, stack_b, "ra", diff);
	else
		stack_execute_move_rep(stack_a, stack_b, "rb", diff);
}

static void	stack_execute_moves_rrarrb(t_stack_i *stack_a, t_stack_i *stack_b,
			size_t move_a, size_t move_b)
{
	long long	diff;

	diff = ft_abs_l((long long) move_a - (long long) move_b);
	if (move_a > move_b)
		stack_execute_move_rep(stack_a, stack_b, "rra", diff);
	else
		stack_execute_move_rep(stack_a, stack_b, "rrb", diff);
}

void	exec_moves_turk(t_stack_i *stack_a, t_stack_i *stack_b,
			t_n_moves moves, t_turk_moves moves_select)
{
	if (moves_select == RARB)
	{
		stack_execute_move_rep(stack_a, stack_b, "rr", moves.rr);
		stack_execute_moves_rarb(stack_a, stack_b, moves.ra, moves.rb);
	}
	else if (moves_select == RRARRB)
	{
		stack_execute_move_rep(stack_a, stack_b, "rrr", moves.rrr);
		stack_execute_moves_rrarrb(stack_a, stack_b, moves.rra, moves.rrb);
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

void	perform_min_moves(t_stack_i *stack_a, t_stack_i *stack_b,
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
	if (moves_combs.ra_rb == min_moves)
		exec_moves_turk(stack_a, stack_b, moves, RARB);
	else if (moves_combs.rra_rrb == min_moves)
		exec_moves_turk(stack_a, stack_b, moves, RRARRB);
	else if (moves_combs.ra_rrb == min_moves)
		exec_moves_turk(stack_a, stack_b, moves, RARRB);
	else if (moves_combs.rra_rb == min_moves)
		exec_moves_turk(stack_a, stack_b, moves, RRARB);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_pushswap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/03/03 16:23:19 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_swap(t_stack_i *stack)
{
	long long	aux_value;
	long long	second_top;

	if (stack->size < 2)
		return ;
	if (stack->top == 0)
		second_top = stack->capacity - 1;
	else
		second_top = stack->top - 1;
	aux_value = stack->array[stack->top];
	stack->array[stack->top] = stack->array[second_top];
	stack->array[second_top] = aux_value;
}

void	swap(t_stack_i *stack)
{
	_swap(stack);
}

void	sswap(t_stack_i *stack_a, t_stack_i *stack_b)
{
	_swap(stack_a);
	_swap(stack_b);
}

void	push(t_stack_i *stack_dst, t_stack_i *stack_src)
{
	if (stack_is_empty(stack_src))
		return ;
	stack_push(stack_dst, stack_pop(stack_src));
}

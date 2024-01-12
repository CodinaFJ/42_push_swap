/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:04:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 13:30:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    reorder_big_to_top(t_stack_i *stack, int iteration)
{
	size_t  chunk_size;
	size_t  i;

	(void) iteration;
	i = 0;
	chunk_size = 25;
	while (i < chunk_size * iteration)
	{
		stack_execute_move(NULL, stack, "rb");
		i++;
	}
}

void    push_two_chunks(t_stack_i *stack_a, t_stack_i *stack_b, size_t chunk_limit)
{
	size_t  i;
	size_t  size;

	i = 0;
	size = stack_a->size;
	while (i < size)
	{
		if (stack_top(stack_a) < (long long) chunk_limit)
			push(stack_b, stack_a);
		else if (stack_top(stack_a) > (long long) (stack_a->capacity - chunk_limit))
		{
			push(stack_b, stack_a);
			rotate(stack_b);
		}
		else
			rotate(stack_a);
		//ft_printf("Stack a: Size [%d] Capacity [%d] Top [%d->%d] Bottom [%d->%d]\n", stack_a->size, stack_a->capacity, stack_a->top, stack_a->array[stack_a->top], stack_a->bottom, stack_a->array[stack_a->bottom]);
		//ft_printf("Stack b: Size [%d] Capacity [%d] Top [%d->%d] Bottom [%d->%d]\n", stack_b->size, stack_b->capacity, stack_b->top, stack_b->array[stack_b->top], stack_b->bottom, stack_b->array[stack_b->bottom]);

		if (stack_a->size <= 3)
			break ;
		i++;
	}
	//reorder_big_to_top(stack_b, iteration);
}

void    sort_split(t_stack_i *stack_a, t_stack_i *stack_b, size_t chunk_size)
{
	int		i;

	i = 1;
	while (stack_a->size > 3)
	{
		push_two_chunks(stack_a, stack_b, chunk_size * i);
		i++;
	}
	sort_turk(stack_a, stack_b);
}
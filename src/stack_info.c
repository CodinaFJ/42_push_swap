/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:37:50 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:27 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

size_t	stack_min_indx(const t_stack_i *stack)
{
	size_t		i;
	size_t		index_norm;
	size_t		min_index;
	long long	min;

	i = 0;
	min = LONG_MAX;
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		if (stack->array[index_norm] < min)
		{
			min = stack->array[index_norm];
			min_index = stack->bottom + i;
		}
		i++;
	}
	return (min_index);
}

size_t	stack_max_indx(const t_stack_i *stack)
{
	size_t		i;
	size_t		index_norm;
	size_t		max_index;
	long long	max;

	i = 0;
	max = -1;
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		if (stack->array[index_norm] > max)
		{
			max = stack->array[index_norm];
			max_index = stack->bottom + i;
		}
		i++;
	}
	return (max_index);
}

long long	stack_top(const t_stack_i *stack)
{
	size_t	index;

	index = (stack->bottom + stack->size - 1) % stack->capacity;
	return (stack->array[index]);
}

int	stack_is_empty(t_stack_i *stack)
{
	return (stack->size == 0);
}

int	stack_is_full(t_stack_i *stack)
{
	return (stack->size == stack->capacity);
}

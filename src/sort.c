/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:04:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:36:29 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	stack_is_sorted(t_stack_i *stack_norm)
{
	size_t	i;
	int		index;

	i = 0;
	while (i < stack_norm->size)
	{
		index = (stack_norm->bottom + i) % stack_norm->capacity;
		if (stack_norm->array[index] != (int)(stack_norm->size - i - 1))
			return (false);
		i++;
	}
	return (true);
}

void	sort(t_stack_i *stack_a, t_stack_i *stack_b)
{
	if (stack_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3_normalized(stack_a);
	else if (stack_a->size < 99)
		sort_turk(stack_a, stack_b);
	else if (stack_a->size < 499)
		sort_chunks(stack_a, stack_b, CHUNK_SIZE_100);
	else
		sort_chunks(stack_a, stack_b, CHUNK_SIZE_500);
}

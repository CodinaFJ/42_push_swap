/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:04:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 15:13:06 by jcodina-         ###   ########.fr       */
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
		if (stack_norm->array[index] != (int) (stack_norm->size - i - 1))
			return (false);
		i++;
	}
	return (true);
}

void    sort(t_stack_i *stack_a, t_stack_i *stack_b)
{
    (void) stack_a;
    (void) stack_b;

    if (stack_a->size == 2)
        sort_2(stack_a);
    else if (stack_a->size == 3)
        sort_3(stack_a);
}

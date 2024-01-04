/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:56:27 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/04 18:36:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	stack_push(t_stack_i *stack, int n)
{
    if (stack->top == stack->size)
    {
        ft_printf("[ERROR] Stack overflow");
        return (1);
    }
    stack->array[stack->top] = n;
    stack->top++;
    return (0);
}

int	stack_pop(t_stack_i *stack)
{
    if (stack->top == 0)
    {
        ft_printf("[ERROR] Stack underflow\n");
        return (INT_MIN);
    }
    stack->top--;
    return (stack->array[stack->top]);
}

int stack_empty(t_stack_i* stack)
{
	return (stack->top == 0);
}

void stack_clear(t_stack_i* stack)
{
	stack->top = 0;
}

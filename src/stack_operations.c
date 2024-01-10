/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:56:27 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 11:24:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/stack.h"

int	stack_push(t_stack_i *stack, int n)
{
    if (stack->size == stack->capacity)
    {
        ft_printf("[ERROR] Stack overflow");
        return (1);
    }
    if (stack->size > 0)
        stack->top = (stack->top + 1) % stack->capacity;
    stack->array[stack->top] = n;
    stack->size++;
    return (0);
}

int	stack_push_bottom(t_stack_i *stack, int n)
{
    if (stack->size == stack->capacity)
    {
        ft_printf("[ERROR] Stack overflow");
        return (1);
    }
    if (stack->bottom == 0 && stack->size > 0)
        stack->bottom = stack->capacity - 1;
    else if (stack-> size > 0)
        stack->bottom--;
    stack->array[stack->bottom] = n;
    stack->size++;
    return (0);
}

int	stack_pop(t_stack_i *stack)
{
    int value;
    
    if (stack->size == 0)
    {
        ft_printf("[ERROR] Stack underflow\n");
        return (INT_MIN);
    }
    value = stack->array[stack->top];
    if (stack->top == 0)
        stack->top = stack->capacity - 1;
    else
        stack->top--;
    stack->size--;
    return (value);
}

int	stack_pop_bottom(t_stack_i *stack)
{
    int value;
    
    if (stack->size == 0)
    {
        ft_printf("[ERROR] Stack underflow\n");
        return (INT_MIN);
    }
    value = stack->array[stack->bottom];
    stack->bottom = (stack->bottom + 1) % stack->capacity;
    stack->size--;
    return (value);
}

void stack_clear(t_stack_i* stack)
{
	stack->top = 0;
    stack->bottom = 0;
    stack->size = 0;
}

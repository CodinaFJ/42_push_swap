/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 12:37:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    swap(t_stack_i *stack)
{
    int aux_value;
    int second_top;
    
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

void    push(t_stack_i *stack_dst, t_stack_i *stack_src)
{
    if (stack_is_empty(stack_src))
        return ;
    stack_push(stack_dst, stack_pop(stack_src));
}

void    rotate(t_stack_i *stack)
{
    stack_push_bottom(stack, stack_pop(stack));
}

void    r_rotate(t_stack_i *stack)
{
    stack_push(stack, stack_pop_bottom(stack));
}
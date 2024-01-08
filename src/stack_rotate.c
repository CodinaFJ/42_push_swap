/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:03:18 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 13:07:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    _rotate(t_stack_i *stack, t_bool reverse)
{
    if (reverse == false)
        stack_push_bottom(stack, stack_pop(stack));
    else
        stack_push(stack, stack_pop_bottom(stack));
}

void    rotate(t_stack_i *stack)
{
    ft_printf("r%c\n", stack->id);
    _rotate(stack, false);
}

void    r_rotate(t_stack_i *stack)
{
    ft_printf("rr%c\n", stack->id);
    _rotate(stack, true);
}

void    rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    ft_printf("rr\n");
    _rotate(stack_a, false);
    _rotate(stack_b, false);
}

void    r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    ft_printf("rrr\n");
    _rotate(stack_a, true);
    _rotate(stack_b, true);
}
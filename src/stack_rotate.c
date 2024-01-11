/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:03:18 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/11 20:26:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void    _rotate(t_stack_i *stack, t_rotate_direction direction)
{
    if (direction == FORWARD)
        stack_push_bottom(stack, stack_pop(stack));
    else if (direction == REVERSE)
        stack_push(stack, stack_pop_bottom(stack));
}

void    rotate(t_stack_i *stack)
{
    ft_printf("r%c\n", stack->id);
    _rotate(stack, FORWARD);
}

void    r_rotate(t_stack_i *stack)
{
    ft_printf("rr%c\n", stack->id);
    _rotate(stack, REVERSE);
}

void    rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    ft_printf("rr\n");
    _rotate(stack_a, FORWARD);
    _rotate(stack_b, FORWARD);
}

void    r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    ft_printf("rrr\n");
    _rotate(stack_a, REVERSE);
    _rotate(stack_b, REVERSE);
}
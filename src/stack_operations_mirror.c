/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:36:22 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 12:40:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sswap(t_stack_i *stack_a, t_stack_i *stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

void    rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

void    r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
}
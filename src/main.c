/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 13:23:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    t_stack_i *stack_a = stack_new(10, 'a');
    t_stack_i *stack_b = stack_new(10, 'b');

    stack_push(stack_a, 1);
    stack_push(stack_a, 2);
    stack_push(stack_a, 3);
    stack_push(stack_a, 4);
    stack_push(stack_a, 5);
    stack_push(stack_a, 6);
    stack_push(stack_a, 7);
    stack_push(stack_a, 8);
    
    push(stack_b, stack_a);
    swap(stack_a);
    push(stack_b, stack_a);
    stack_print(stack_a);
    stack_print(stack_b);
    r_rotate(stack_a);
    /*push(stack_b, stack_a);
    sswap(stack_a, stack_b);
    push(stack_a, stack_b);*/

    stack_print(stack_a);
    stack_print(stack_b);
    
    stack_free(stack_a);
    stack_free(stack_b);
    return (0);
}
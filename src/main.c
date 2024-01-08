/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 12:14:59 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    t_stack_i *stack = stack_new(5);

    ft_printf("Is stack empty? %d\n", stack_is_empty(stack));
    stack_push_bottom(stack, 2);
    stack_print(stack);
    stack_push_bottom(stack, 55);
    stack_print(stack);
    stack_push(stack, -8);
    stack_print(stack);
    stack_push(stack, -100);
    stack_print(stack);
    ft_printf("Stack pop: %d\n", stack_pop_bottom(stack));
    stack_print(stack);
    stack_push_bottom(stack, 666);
    stack_print(stack);
    ft_printf("Is stack empty? %d\n", stack_is_empty(stack));
    ft_printf("Stack pop: %d\n", stack_pop(stack));
    ft_printf("Is stack empty? %d\n", stack_is_empty(stack));
    stack_clear(stack);
    stack_print(stack);
    ft_printf("Is stack empty? %d\n", stack_is_empty(stack));
    stack_free(stack);
    return (0);
}
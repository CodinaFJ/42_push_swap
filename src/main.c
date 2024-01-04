/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/04 18:40:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    t_stack_i *stack = stack_init(3);

    ft_printf("Is stack empty? %d\n", stack_empty(stack));
    stack_push(stack, 2);
    stack_print(stack);
    stack_push(stack, 55);
    stack_print(stack);
    stack_push(stack, -8);
    stack_print(stack);
    stack_push(stack, -100);
    stack_print(stack);
    stack_push(stack, 666);
    stack_print(stack);
    ft_printf("Is stack empty? %d\n", stack_empty(stack));
    ft_printf("Stack pop: %d\n", stack_pop(stack));
    ft_printf("Is stack empty? %d\n", stack_empty(stack));
    stack_clear(stack);
    stack_print(stack);
    ft_printf("Is stack empty? %d\n", stack_empty(stack));
    stack_free(stack);
    return (0);
}
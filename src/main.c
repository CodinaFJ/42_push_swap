/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 13:53:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort(t_stack_i *stack_a, t_stack_i *stack_b)
{
    (void) stack_a;
    (void) stack_b;

    if (stack_a->size == 2)
        sort_2(stack_a);
    else if (stack_a->size == 3)
        sort_3(stack_a);
}

void    end_program(t_stack_i *stack_a, t_stack_i *stack_b)
{
    stack_free(stack_a);
    stack_free(stack_b);
    exit(0);
}

int main(int argc, char **argv)
{
    t_stack_i	*stack_a;
    t_stack_i	*stack_b;
    
    extract_valid_input(argc, argv, &stack_a, &stack_b);
    //stack_print(stack_a);
    sort(stack_a, stack_b);
    //stack_print(stack_a);
    end_program(stack_a, stack_b);
    return (0);
}

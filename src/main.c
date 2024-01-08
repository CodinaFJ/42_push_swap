/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 17:06:50 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack_i	*stack_a;
    t_stack_i	*stack_b;
    int			size;
    char		***input;
    
    if (argc == 1)
        exit_error(INPUT, "No input");
    input = input_parse(argc, argv, &size);
    stack_a = input_to_stack(input, size);
    stack_b = stack_new(size, 'b');
	input_free(input);
	if (stack_a == NULL || stack_b == NULL)
		exit_error_free_stacks(MEMORY, "Error allocating stacks", stack_a, stack_b);
    stack_print(stack_a);
    stack_free(stack_a);
    stack_free(stack_b);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/09 11:34:27 by jcodina-         ###   ########.fr       */
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
        return (1);
    input = input_parse(argc, argv, &size);
    stack_a = input_to_stack(input, size);
    stack_b = stack_new(size, 'b');
	input_free(input);
	if (stack_a == NULL || stack_b == NULL || stack_a->size == 0)
		exit_error_free_stacks(MEMORY, "Error", stack_a, stack_b);
    stack_print(stack_a);
    stack_free(stack_a);
    stack_free(stack_b);
    return (0);
}

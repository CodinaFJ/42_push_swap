/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 18:40:59 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_leaks()
{
	system("leaks push_swap");
}

void	end_program(t_stack_i *stack_a, t_stack_i *stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
	ft_leaks();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack_i	*stack_a;
	t_stack_i	*stack_b;

	extract_valid_input(argc, argv, &stack_a, &stack_b);
	sort(stack_a, stack_b);
	end_program(stack_a, stack_b);
	ft_leaks();
	return (0);
}

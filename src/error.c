/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:24 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 18:36:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error_free_stacks(t_error error_type, char *msg,
			t_stack_i *stack_a, t_stack_i *stack_b)
{
	stack_free(&stack_a);
	stack_free(&stack_b);
	exit_error(error_type, msg);
}

void	exit_error(t_error error_type, char *msg)
{
	if (error_type == INPUT)
		ft_putstr_fd(msg, 2);
	else if (error_type == MEMORY)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

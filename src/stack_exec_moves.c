/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exec_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:05 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/11 20:21:33 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_execute_move(t_stack_i *stack_a, t_stack_i *stack_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(str, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(str, "ss"))
		sswap(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(str, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(str, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(str, "rr"))
		rrotate(stack_a ,stack_b);
	else if (!ft_strcmp(str, "rra"))
		r_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb"))
		r_rotate(stack_b);
	else if (!ft_strcmp(str, "rrr"))
		r_rrotate(stack_a, stack_b);
	else
		ft_printf("[ERROR] Wrong movement\n");
}

void    stack_execute_move_rep(t_stack_i *stack_a, t_stack_i *stack_b, char *str, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		stack_execute_move(stack_a, stack_b, str);
		i++;
	}
}

void    stack_execute_moves(t_stack_i *stack_a, t_stack_i *stack_b, char *str)
{
	char	**strs;
	size_t	i;
	
	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i] != NULL)
	{
		stack_execute_move(stack_a, stack_b, strs[i]);
		i++;	
	}
	ft_strs_free(strs);
}
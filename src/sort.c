/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:04:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 13:49:52 by jcodina-         ###   ########.fr       */
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

void    stack_execute_moves(t_stack_i *stack_a, t_stack_i *stack_b, char *str)
{
	char	**strs;
	int		i;
	
	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i] != NULL)
	{
		stack_execute_move(stack_a, stack_b, strs[i]);
		i++;	
	}
	ft_strs_free(strs);
}

t_bool	stack_is_sorted(t_stack_i *stack_norm)
{
	size_t	i;
	int		index;

	i = 0;
	while (i < stack_norm->size)
	{
		index = (stack_norm->bottom + i) % stack_norm->capacity;
		if (stack_norm->array[index] != (int) (stack_norm->size - i - 1))
			return (false);
		i++;
	}
	return (true);
}

void    sort_3(t_stack_i *stack)
{
	if (stack_is_sorted(stack))
		return ;
	if (stack_cmp_str(stack, "0 2 1"))
		stack_execute_moves(stack, NULL, SORT_021);
	else if (stack_cmp_str(stack, "1 0 2"))
		stack_execute_moves(stack, NULL, SORT_102);
	else if (stack_cmp_str(stack, "1 2 0"))
		stack_execute_moves(stack, NULL, SORT_120);
	else if (stack_cmp_str(stack, "2 0 1"))
		stack_execute_moves(stack, NULL, SORT_201);
	else if (stack_cmp_str(stack, "2 1 0"))
		stack_execute_moves(stack, NULL, SORT_210);
}

void    sort_2(t_stack_i *stack)
{
	if (stack_is_sorted(stack))
		return ;
	stack_execute_move(stack, NULL, "sa");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:59:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 15:13:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int stack_find_index(t_stack_i *stack, enum e_bool (*cmp)(int winner, int candidate))
{
    size_t	i;
	int		index;
	int		winner;
    int 	*array;

	winner = stack->bottom;
    array = stack->array;
	i = 0;
    while (i < stack->size)
	{
		index = (stack->bottom + i) % stack->capacity;
		if (!cmp(array[winner], array[index]))
			winner = index;
		i++;
	}
	return (winner);
}

t_bool	stack_cmp_str(t_stack_i *stack, char *str)
{
	char	**strs;
	size_t	i;
	int		index;

	i = 0;
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (false);
	while (i < stack->size && strs[i] != NULL)
	{
		index = (stack->top - i - 1) % stack->capacity;
		if (stack->array[index] != strs[i][0] - '0')
			return (false);
		i++;
	}
	return (true);
}

static int	how_many_lower(t_stack_i *stack, int value)
{
	size_t	i;
	int		index;
	int		n;

	n = 0;
	i = 0;
    while (i < stack->size)
	{
		index = (stack->bottom + i) % stack->capacity;
		if (stack->array[index] < value)
			n++;
		i++;
	}
	return (n);
}

void	stack_normalize(t_stack_i *stack)
{
	size_t		i;
	int			index;
	int			*norm_array;
	
	norm_array = ft_calloc(stack->capacity, sizeof(int));
	if (norm_array == NULL)
		return ;
	ft_bzero(norm_array, stack->capacity * sizeof(int));
	i = 0;
	while (i < stack->size)
	{
		index = (stack->bottom + i) % stack->capacity;
		norm_array[index] = how_many_lower(stack, stack->array[index]);
		i++;
	}
	free(stack->array);
	stack->array = norm_array;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:59:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

size_t	stack_min_proxtonbr(const t_stack_i *stack, int nbr)
{
	size_t		i;
	size_t		index_norm;
	size_t		min_index;
	long long	min;

	i = 0;
	min_index = stack_max_indx(stack);
	min = stack->array[min_index % stack->capacity];
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		if (stack->array[index_norm] < nbr
			&& (stack->array[index_norm] > min || (min > nbr)))
		{
			min_index = stack->bottom + i;
			min = stack->array[index_norm];
		}
		i++;
	}
	return (min_index - stack->bottom);
}

size_t	stack_max_proxtonbr(const t_stack_i *stack, int nbr)
{
	size_t		i;
	size_t		index_norm;
	size_t		max_index;
	long long	max;

	i = 0;
	max_index = stack_min_indx(stack);
	max = stack->array[max_index % stack->capacity];
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		if (stack->array[index_norm] > nbr
			&& (stack->array[index_norm] < max || (max < nbr)))
		{
			max_index = stack->bottom + i;
			max = stack->array[index_norm];
		}
		i++;
	}
	return (max_index - stack->bottom);
}

t_bool	stack_cmp_str(t_stack_i *stack, char *str)
{
	char	**strs;
	size_t	i;
	size_t	index_norm;

	i = 0;
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (false);
	while (i < stack->size && strs[i] != NULL)
	{
		index_norm = (stack->bottom + stack->size - i - 1) % stack->capacity;
		if (stack->array[index_norm] != strs[i][0] - '0')
			return (false);
		i++;
	}
	return (true);
}

static int	how_many_lower(t_stack_i *stack, long long value)
{
	size_t		i;
	size_t		index_norm;
	long long	n;

	n = 0;
	i = 0;
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		if (stack->array[index_norm] < value)
			n++;
		i++;
	}
	return (n);
}

void	stack_normalize(t_stack_i *stack)
{
	size_t		i;
	size_t		index_norm;
	long long	*norm_array;

	norm_array = ft_calloc(stack->capacity, sizeof(long long));
	if (norm_array == NULL)
		return ;
	ft_bzero(norm_array, stack->capacity * sizeof(long long));
	i = 0;
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		norm_array[index_norm] = how_many_lower(
				stack,
				stack->array[index_norm]);
		i++;
	}
	free(stack->array);
	stack->array = norm_array;
}

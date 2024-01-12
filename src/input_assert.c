/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_assert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:42 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 16:17:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		i++;
		if (str[i] == '\0')
			return (true);
	}
	return (false);
}

t_bool	assert_is_numbers(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		if (!is_number(strs[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	assert_no_repeated(t_stack_i *norm_stack)
{
	size_t	i;
	t_bool	*seen;
	int		index;

	i = 0;
	seen = ft_calloc(norm_stack->size, sizeof(t_bool));
	ft_bzero(seen, norm_stack->size * sizeof(t_bool));
	while (i < norm_stack->size)
	{
		index = (norm_stack->bottom + i) % norm_stack->capacity;
		if (seen[norm_stack->array[index]] == true)
		{
			free(seen);
			return (false);
		}
		else
			seen[norm_stack->array[index]] = true;
		i++;
	}
	return (true);
}

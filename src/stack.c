/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:17 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 13:06:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void stack_print(t_stack_i *stack)
{
	size_t	i;
	size_t	size;
	
	size = stack->size;
	i = stack->top;
	ft_printf("\nPRINT STACK %c\n----------\n", stack->id);
	if (size == 0)
		ft_printf("stack empty\n");
	else
	{
		while (size > 0)
		{
			ft_printf("%d\n", stack->array[i]);
			size--;
			if (i == 0)
				i = stack->capacity - 1;
			else
				i--;
		}
	}
	ft_printf("----------\n");
}

t_stack_i   *stack_new(size_t capacity, char id)
{
	t_stack_i   *stack;

	stack = malloc(sizeof(t_stack_i));
	if (!stack)
		return (NULL);
	stack->capacity  = capacity;
	stack->array = malloc(sizeof(long long) * capacity);
	if (stack->array == NULL)
	{
		free(stack);
		return (NULL);
	}
	ft_bzero(stack->array, sizeof(long long) * capacity);
	stack->id = id;
	stack->size = 0;
	stack->top = 0;
	stack->bottom = 0;
	return (stack);
}

t_stack_i	*stack_dup(t_stack_i *stack)
{
	t_stack_i	*stack_dup;
	size_t		i;
	
	i = 0;
	stack_dup = stack_new(stack->capacity, stack->id);
	if (stack_dup == NULL)
		return (NULL);
	stack_dup->bottom = stack->bottom;
	stack_dup->top = stack->top;
	stack_dup->size = stack->size;
	while (i < stack->capacity)
	{
		stack_dup->array[i] = stack->array[i];
		i++;
	}
	return (stack_dup);
}

void    stack_free(t_stack_i *stack)
{
	if (stack == NULL)
		return ;
	if (stack->array != NULL)
		free(stack->array);
	free(stack);
}

long long	stack_top(const t_stack_i* stack)
{
	size_t	index;

	index = (stack->bottom + stack->size - 1) % stack->capacity;
	return (stack->array[index]);
}

int stack_is_empty(t_stack_i* stack)
{
	return (stack->size == 0);
}

int stack_is_full(t_stack_i* stack)
{
	return (stack->size == stack->capacity);
}

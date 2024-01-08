/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:17 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 12:19:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void stack_print(t_stack_i *stack)
{
	size_t	i;
    int     size;
    
    size = stack->size;
	i = stack->top;
	ft_printf("\nPRINT STACK\n----------\n");
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

t_stack_i   *stack_new(size_t capacity)
{
    t_stack_i   *stack;

    stack = malloc(sizeof(t_stack_i));
    if (!stack)
        return (NULL);
    stack->capacity  = capacity;
    stack->array = malloc(sizeof(int) * capacity);
    if (stack->array == NULL)
    {
        free(stack);
        return (NULL);
    }
    ft_bzero(stack->array, sizeof(int) * capacity);
    stack->size = 0;
    stack->top = 0;
    stack->bottom = 0;
    return (stack);
}

void    stack_free(t_stack_i *stack)
{
    free(stack->array);
    free(stack);
}

int stack_is_empty(t_stack_i* stack)
{
	return (stack->size == 0);
}

int stack_is_full(t_stack_i* stack)
{
	return (stack->size == stack->capacity);
}

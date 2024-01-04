/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:17 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/04 18:25:12 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void stack_print(t_stack_i *stack)
{
	size_t	i;

	i = stack->top;
	ft_printf("\nPRINT STACK\n----------\n");
	if (stack->top == 0)
		ft_printf("stack empty\n");
	else
	{
		while (i > 0)
		{
			i--;
			ft_printf("%d\n", stack->array[i]);
		}
	}
	ft_printf("----------\n");
}

t_stack_i   *stack_init(size_t size)
{
    t_stack_i   *stack;

    stack = malloc(sizeof(t_stack_i));
    if (!stack)
        return (NULL);
    stack->array = malloc(sizeof(int) * size);
    if (stack->array == NULL)
    {
        free(stack);
        return (NULL);
    }
    ft_bzero(stack->array, sizeof(int) * size);
    stack->size = size;
    stack->top = 0;
    return (stack);
}

void    stack_free(t_stack_i *stack)
{
    free(stack->array);
    free(stack);
}

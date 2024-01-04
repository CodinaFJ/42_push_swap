/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:12 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/04 18:34:10 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/ft_printf/ft_printf.h"

/* ************************************************************************** */
/*   Typedefs															      */
/* ************************************************************************** */

typedef struct s_stack_i
{
	int		*array;
	size_t  size;
	size_t	top;
}	t_stack_i;

/* ************************************************************************** */
/*   Functions															      */
/* ************************************************************************** */

/*									STACK									  */

int			stack_push(t_stack_i *stack, int n);
int			stack_pop(t_stack_i *stack);
int			stack_empty(t_stack_i *stack);
void		stack_clear(t_stack_i *stack);

/*									STACK MGMT								  */

t_stack_i	*stack_init(size_t size);
void		stack_free(t_stack_i *stack);
void		stack_print(t_stack_i *stack);

#endif
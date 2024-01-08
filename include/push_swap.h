/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:12 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 13:04:15 by jcodina-         ###   ########.fr       */
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

typedef enum e_bool
{
	true,
	false
}	t_bool;

typedef struct s_stack_i
{
	char	id;
	int		top;
	int		bottom;
	size_t  size;
	size_t	capacity;
	int		*array;
}	t_stack_i;

t_stack_i	*stack_new(size_t size, char id);
void		stack_free(t_stack_i *stack);
void		stack_print(t_stack_i *stack);
int			stack_is_empty(t_stack_i *stack);
int			stack_is_full(t_stack_i *stack);
void		stack_clear(t_stack_i *stack);

/* ************************************************************************** */
/*   Functions															      */
/* ************************************************************************** */

/*									STACK PUSHPOPCLEAR						  */

int			stack_push(t_stack_i *stack, int n);
int			stack_push_bottom(t_stack_i *stack, int n);
int			stack_pop(t_stack_i *stack);
int			stack_pop_bottom(t_stack_i *stack);

/*									STACK_OPERATIONS						  */
void    	swap(t_stack_i *stack);
void    	push(t_stack_i *stack_dst, t_stack_i *stack_src);
void    	rotate(t_stack_i *stack);
void    	r_rotate(t_stack_i *stack);
void    	sswap(t_stack_i *stack_a, t_stack_i *stack_b);
void    	rrotate(t_stack_i *stack_a, t_stack_i *stack_b);
void    	r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b);

#endif
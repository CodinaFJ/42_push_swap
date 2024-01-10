/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:12 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 12:07:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "stack.h"

/* ************************************************************************** */
/*   Typedefs															      */
/* ************************************************************************** */

# ifndef _E_BOOL
#  define _E_BOOL
	typedef enum e_bool
	{
		false = 0,
		true = 1
	}	t_bool;
#endif

typedef enum e_error
{
	INPUT,
	MEMORY
}	t_error;

typedef enum e_rotate_direction
{
	FORWARD,
	REVERSE
}	t_rotate_direction;

/* ************************************************************************** */
/*   Functions															      */
/* ************************************************************************** */

/*									STACK OPERATIONS						  */

int			stack_push(t_stack_i *stack, int n);
int			stack_push_bottom(t_stack_i *stack, int n);
int			stack_pop(t_stack_i *stack);
int			stack_pop_bottom(t_stack_i *stack);

/*									STACK PUSH SWAP ROTATE					  */
void    	swap(t_stack_i *stack);
void    	push(t_stack_i *stack_dst, t_stack_i *stack_src);
void    	rotate(t_stack_i *stack);
void    	r_rotate(t_stack_i *stack);
void    	sswap(t_stack_i *stack_a, t_stack_i *stack_b);
void    	rrotate(t_stack_i *stack_a, t_stack_i *stack_b);
void    	r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b);

/*									INPUT									*/

t_stack_i	*input_to_stack(char ***input, int size);
char		***input_parse(int argc, char **argv, int *size_nums);
void		input_free(char ***input);

/*									INPUT ASSERT							  */

t_bool		assert_is_numbers(char **strs);
t_bool		assert_no_repeated(t_stack_i *norm_stack);

/*									ERROR									  */

void    	exit_error(t_error error_type, char *msg);
void    	exit_error_free_stacks(t_error error_type, char *msg,
				t_stack_i *stack_a, t_stack_i *stack_b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:12 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 13:31:15 by jcodina-         ###   ########.fr       */
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
# include "sort_precomp.h"
# define CHUNK_SIZE_100 20
# define CHUNK_SIZE_500 100

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

typedef enum e_turk_moves
{
	RARB,
	RRARRB,
	RARRB,
	RRARB
}	t_turk_moves;

typedef struct s_n_moves
{
	size_t	pa;
	size_t	pb;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_n_moves;

typedef struct s_moves_combs
{
	size_t	ra_rb;
	size_t	rra_rrb;
	size_t	ra_rrb;
	size_t	rra_rb;
}	t_moves_combs;


/* ************************************************************************** */
/*   Functions															      */
/* ************************************************************************** */

/*									STACK PUSH SWAP ROTATE					  */

void    	swap(t_stack_i *stack);
void    	push(t_stack_i *stack_dst, t_stack_i *stack_src);
void    	rotate(t_stack_i *stack);
void    	r_rotate(t_stack_i *stack);
void    	sswap(t_stack_i *stack_a, t_stack_i *stack_b);
void    	rrotate(t_stack_i *stack_a, t_stack_i *stack_b);
void    	r_rrotate(t_stack_i *stack_a, t_stack_i *stack_b);

/*									INPUT									*/

t_stack_i	*input_to_stack(char ***input, size_t size);
char		***input_parse(int argc, char **argv, size_t *size_nums);
void		input_free(char ***input);
void		extract_valid_input(int argc, char **argv, t_stack_i **stack_a, t_stack_i **stack_b);

/*									INPUT ASSERT							  */

t_bool		assert_is_numbers(char **strs);
t_bool		assert_no_repeated(t_stack_i *norm_stack);

/*									ERROR									  */

void    	exit_error(t_error error_type, char *msg);
void    	exit_error_free_stacks(t_error error_type, char *msg,
				t_stack_i *stack_a, t_stack_i *stack_b);

/*									STACK EXECUTE MOVES						  */

void    	stack_execute_moves(t_stack_i *stack_a, t_stack_i *stack_b, char *str);
void    	stack_execute_move_rep(t_stack_i *stack_a, t_stack_i *stack_b, char *str, size_t n);
void		stack_execute_move(t_stack_i *stack_a, t_stack_i *stack_b, char *str);

/*									SORT									  */

void    	sort(t_stack_i *stack_a, t_stack_i *stack_b);
t_bool		stack_is_sorted(t_stack_i *stack_norm);
void    	sort_3(t_stack_i *stack);
void    	sort_3_normalized(t_stack_i *stack);
void    	sort_2(t_stack_i *stack);
void		sort_turk(t_stack_i *stack_a, t_stack_i *stack_b);
void    	sort_split(t_stack_i *stack_a, t_stack_i *stack_b, size_t chunk_size);

#endif
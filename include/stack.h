/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 17:47:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# ifndef _E_BOOL
#  define _E_BOOL

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;
# endif

typedef struct s_stack_i
{
	char			id;
	size_t			top;
	size_t			bottom;
	size_t			size;
	size_t			capacity;
	long long		*array;
}	t_stack_i;

/*									STACK BASICS							  */

t_stack_i	*stack_new(size_t size, char id);
void		stack_free(t_stack_i *stack);
void		stack_print(t_stack_i *stack);
void		stack_clear(t_stack_i *stack);
t_stack_i	*stack_dup(t_stack_i *stack);

/*									STACK INFO								  */

int			stack_is_full(t_stack_i *stack);
int			stack_is_empty(t_stack_i *stack);
long long	stack_top(const t_stack_i *stack);
size_t		stack_max_indx(const t_stack_i *stack);
size_t		stack_min_indx(const t_stack_i *stack);

/*									STACK OPERATIONS						  */

int			stack_push(t_stack_i *stack, long long n);
int			stack_push_bottom(t_stack_i *stack, long long n);
long long	stack_pop(t_stack_i *stack);
long long	stack_pop_bottom(t_stack_i *stack);

/*									STACK ARITHMETIC						  */
/*
 To iterate through a stack:
 
	size_t	i;
	size_t	index_norm;

	i = 0;
	while (i < stack->size)
	{
		index_norm = (stack->bottom + i) % stack->capacity;
		i++
	}

 In general:
 
	index = stack->bottom + i;
	index_norm = (stack->bottom + i) % stack->capacity;
*/

int			stack_find_index(
				t_stack_i *stack,
				enum e_bool (*cmp)(int winner, int candidate));
void		stack_normalize(t_stack_i *stack);
t_bool		stack_cmp_str(t_stack_i *stack, char *str);
size_t		stack_min_proxtonbr(const t_stack_i *stack, int nbr);
size_t		stack_max_proxtonbr(const t_stack_i *stack, int nbr);
#endif
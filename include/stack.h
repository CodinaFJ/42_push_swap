/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/10 12:06:12 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H
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
#endif


typedef struct s_stack_i
{
	char	id;
	int		top;
	int		bottom;
	size_t  size;
	size_t	capacity;
	int		*array;
}	t_stack_i;

/*									STACK BASICS							  */

t_stack_i	*stack_new(size_t size, char id);
void		stack_free(t_stack_i *stack);
void		stack_print(t_stack_i *stack);
int			stack_is_empty(t_stack_i *stack);
int			stack_is_full(t_stack_i *stack);
void		stack_clear(t_stack_i *stack);

/*									STACK ARITHMETIC						  */

int			stack_find_index(
				t_stack_i *stack,
				enum e_bool (*cmp)(int winner, int candidate));
void		stack_normalize(t_stack_i *stack);

#endif
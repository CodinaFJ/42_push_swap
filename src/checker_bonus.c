/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:06:25 by jcodina-          #+#    #+#             */
/*   Updated: 2024/03/03 20:03:05 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	end_program(t_stack_i *stack_a, t_stack_i *stack_b, char *instructions)
{
	stack_free(stack_a);
	stack_free(stack_b);
	if (instructions != NULL)
		free(instructions);
	exit(0);
}

static t_bool	is_valid_instruction(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
		|| ft_strcmp(str, "ss") == 0)
		return (true);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0
		|| ft_strcmp(str, "rr") == 0)
		return (true);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
		|| ft_strcmp(str, "rrr") == 0)
		return (true);
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		return (true);
	return (false);
}

static char	*build_instructions(char *instructions)
{
	char	*str;
	char	*aux;

	while (1)
	{
		aux = get_next_line(0);
		if (aux == NULL)
			return (instructions);
		else if (ft_strcmp(aux, "\n") == 0)
		{
			free(aux);
			return (instructions);
		}
		str = ft_strtrim(aux, "\n");
		free(aux);
		if (!is_valid_instruction(str))
			exit_error(INPUT, "Invalid instruction");
		instructions = ft_strjoin_free_gnl(&instructions, &str);
		aux = ft_strjoin(instructions, " ");
		free(instructions);
		instructions = aux;
		free(aux);
	}
}

char	*read_instructions(void)
{
	char	*instructions;
	char	*aux;

	aux = NULL;
	instructions = build_instructions(ft_strdup(""));
	if (instructions != NULL)
	{
		aux = ft_strtrim(instructions, " ");
		free(instructions);
	}
	return (aux);
}

int	main(int argc, char **argv)
{
	t_stack_i	*stack_a;
	t_stack_i	*stack_b;
	char		*instructions;

	extract_valid_input(argc, argv, &stack_a, &stack_b);
	instructions = read_instructions();
	stack_execute_moves(stack_a, stack_b, instructions);
	if (stack_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	end_program(stack_a, stack_b, instructions);
	return (0);
}

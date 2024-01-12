/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:44:56 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/12 18:20:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	input_free(char ***input)
{
	int	i;
	int	j;

	i = 0;
	if (input == NULL)
		return ;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != NULL)
		{
			free(input[i][j]);
			j++;
		}
		free(input[i]);
		i++;
	}
	free(input);
}

char	***input_parse(int argc, char **argv, size_t *size_nums)
{
	int		i;
	char	***input;

	i = 0;
	input = ft_calloc(argc, sizeof(char **));
	if (input == NULL)
		exit_error(MEMORY, "Error");
	input[argc - 1] = NULL;
	while (i < argc - 1)
	{
		input[i] = ft_split(argv[i + 1], ' ');
		if (input[i] == NULL)
		{
			input_free(input);
			exit_error(MEMORY, "Error");
		}
		else if (!assert_is_numbers(input[i]))
		{
			input_free(input);
			exit_error(INPUT, "Error");
		}
		(*size_nums) += (size_t) ft_strs_rows((const char **) input[i]);
		i++;
	}
	return (input);
}

t_stack_i	*input_to_stack(char ***input, size_t size)
{
	int			i;
	int			j;
	long long	num;
	t_stack_i	*stack;

	stack = stack_new(size, 'a');
	if (stack == NULL)
		exit_error(MEMORY, "Cannot allocate stack");
	i = 0;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != NULL)
		{
			num = ft_atol(input[i][j]);
			if (num > INT_MAX || num < INT_MIN)
				exit_error_free_stacks(INPUT, "Only int accepted", stack, NULL);
			stack_push_bottom(stack, num);
			j++;
		}
		i++;
	}
	return (stack);
}

void	extract_valid_input(int argc, char **argv,
			t_stack_i **stack_a, t_stack_i **stack_b)
{
	size_t		size;
	char		***input;

	if (argc == 1)
		exit(1);
	input = input_parse(argc, argv, &size);
	*stack_a = input_to_stack(input, size);
	stack_normalize(*stack_a);
	*stack_b = stack_new(size, 'b');
	input_free(input);
	if (*stack_a == NULL || *stack_b == NULL || (*stack_a)->size == 0)
	{
		exit_error_free_stacks(MEMORY, "Error", *stack_a, *stack_b);
	}
	if (!assert_no_repeated(*stack_a))
	{
		exit_error_free_stacks(INPUT, "Error", *stack_a, *stack_b);
	}
}

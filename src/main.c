/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:51:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 16:22:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    input_free(char ***input)
{
    int i;
    int j;

    i = 0;
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

char    ***parse_input(int argc, char **argv, int *size_nums)
{
    int 	i;
    char	***input;
    
    i = 0;
	input = ft_calloc(argc, sizeof(char **));
	if (input == NULL)
		return (NULL);
    input[argc - 1] = NULL;
    while (i < argc - 1)
    {
        input[i] = ft_split(argv[i + 1], ' ');
        if (input[i] == NULL || !assert_is_numbers(input[i]))
        {
            ft_printf("Error\n");
            return (NULL);
        }
        (*size_nums) += ft_strs_rows((const char **) input[i]);
        i++;
    }
    return (input);
}

t_stack_i    *input_to_stack(char ***input, int size)
{
    int         i;
    int         j;
    long long   num;
    t_stack_i   *stack;
    
    stack = stack_new(size, 'a');
    i = 0;
    while (input[i] != NULL)
    {
        j = 0;
        while (input[i][j] != NULL)
        {
            num = ft_atol(input[i][j]);
            if (num > INT_MAX || num < INT_MIN)
            {
                stack_free(stack);
                return (NULL);
            }
            stack_push_bottom(stack, (int) num);
            j++;
        }
        i++;
    }
    return (stack);
}

int main(int argc, char **argv)
{
    t_stack_i	*stack_a;
    t_stack_i	*stack_b;
    int			size;
    char		***input;
    
    if (argc == 1)
    {
        ft_printf("Error\n");
        return (1);
    }
    input = parse_input(argc, argv, &size);
    stack_a = input_to_stack(input, size);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
        return (1);
	}
    stack_b = stack_new(size, 'b');
    stack_print(stack_a);
    stack_free(stack_a);
    stack_free(stack_b);
    input_free(input);
    return (0);
}
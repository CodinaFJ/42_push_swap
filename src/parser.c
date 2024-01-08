/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:42 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/08 15:57:17 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (ft_isdigit(str[i]))
    {
        i++;
        if (str[i] == '\0')
            return (1);
    }
    return (0);
}

int assert_is_numbers(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != NULL)
    {
        if (!is_number(strs[i]))
            return (0);
        i++;
    }
    return (1);
}

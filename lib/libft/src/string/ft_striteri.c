/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:32:08 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Applies f function to each character of string s.
 * Function f takes as parameters a pointer to the character that it evaluates
 * and its index. Function f can modify string s charactes directly.
 * @param s String to be used on f.
 * @param f Function that evaluates all characters of s.
 * Takes as parameters the pointer to the character to be evaluated 
 * and its index.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

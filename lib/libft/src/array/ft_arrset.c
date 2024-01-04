/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:01:38 by jcodina-          #+#    #+#             */
/*   Updated: 2023/12/31 14:01:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Fills an int array of given length with value d
*/
void	ft_arrset(int *arr, const int d, const unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		arr[i] = d;
		i++;
	}
}


/**
 * Fills a long long array of given length with value d
*/
void	ft_arrsetl(long long *arr, const long long d, const unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		arr[i] = d;
		i++;
	}
}
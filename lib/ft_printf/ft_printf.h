/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:46 by jcodina-          #+#    #+#             */
/*   Updated: 2023/10/24 19:34:53 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/includes/libft.h"

int	ft_printf(const char *format, ...);
int	printf_char(char var);
int	printf_str(char *var);
int	printf_nbr(int var);
int	printf_unbr(unsigned int var);
int	printf_ptr(unsigned long var);
int	printf_hex_low(long long var);
int	printf_hex_upp(long long var);

#endif
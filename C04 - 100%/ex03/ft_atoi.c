/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:10:08 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/23 16:18:03 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

bool	is_symbol(char c)
{
	return (c == '-' || c == '+');
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	negative;

	result = 0;
	negative = 1;
	while (is_space(*str))
		str++;
	while (is_symbol(*str))
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * negative);
}

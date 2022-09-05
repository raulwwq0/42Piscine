/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:26:13 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/31 17:35:37 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (!is_number(str[i]))
			return (-1);
		i++;
	}
	while (is_number(*str) == 1)
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:44:17 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/28 21:47:35 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] <= 47 || str[i] >= 58)
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

int	ft_case_zero_alone(char *str, int *tab, int i)
{
	if (str[i] == '0' && ft_strlen(str) == 1)
	{
		tab[i] = 0;
		tab[i + 1] = -7;
		return (-1);
	}
	return (0);
}

int	*ft_digits(char *str)
{
	int	i;
	int	nbr;
	int	len;
	int	*tab;
	int	pow;

	i = 0;
	nbr = ft_atoi(str);
	len = ft_nbrlen(nbr);
	tab = malloc(len * sizeof(int));
	pow = ft_power(10, len - 1);
	if (ft_case_zero_alone(str, tab, i) == -1)
		return (tab);
	while (i < len)
	{
		tab[i] = nbr / pow * pow;
		pow /= 10;
		nbr -= tab[i];
		i++;
	}
	tab[i] = -7;
	return (tab);
}

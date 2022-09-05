/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:55:09 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/28 19:52:05 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_get_number(int nvl)
{
	int		i;
	char	*str;

	str = (char *) malloc(nvl);
	str[0] = '1';
	i = 1;
	while (i <= nvl)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

int	ft_get_lvl(char *str)
{
	int	len;
	int	lvl;
	int	mod;

	len = ft_strlen(str);
	lvl = len / 3;
	mod = len % 3;
	if (mod != 0)
		lvl++;
	return (lvl);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
}

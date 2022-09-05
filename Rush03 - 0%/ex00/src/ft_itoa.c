/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:53:57 by lguisado          #+#    #+#             */
/*   Updated: 2022/08/28 20:06:22 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	nbr_len(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	int		len2;
	char	*result;

	i = 0;
	len = nbr_len(nbr);
	len2 = len;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len2)
	{
		result[i] = ((nbr / ft_div(len)) % 10) + 48;
		len--;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:24:57 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/31 18:03:07 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*ft_strcat(char *dest, char *src)
{
	char			*default_dest;

	default_dest = dest;
	while (*default_dest != '\0')
	{
		default_dest++;
	}
	while (*src != '\0')
	{
		*default_dest = *src;
		default_dest++;
		src++;
	}
	*default_dest = '\0';
	return (dest);
}

int	ft_str_len(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_array_len(int **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

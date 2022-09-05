/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:35:08 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/28 21:48:53 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	find_and_print(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < DICT_LINES)
	{
		if (ft_strcmp(key, dict[i].key) == 0)
		{
			ft_putstr(dict[i].value);
			ft_putchar(' ');
			return (0);
		}
		i++;
	}
	ft_put_dict_error();
	return (-1);
}

char	*check_valid_input(char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] == ' ')
		i++;
	while (src[i] != '\0')
	{
		if (src[i] < '0' || src[i] > '9')
		{
			ft_put_error();
			break ;
		}		
		src[j] = src[i];
		i++;
		j++;
	}
	while (src[j] != '\0')
		src[j] = '\0';
	return (src);
}

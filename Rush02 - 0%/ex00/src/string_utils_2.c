/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:54:39 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/28 21:10:29 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	find(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < DICT_LINES)
	{
		if (ft_strcmp(key, dict[i].key) == 0)
		{
			return (0);
		}
		i++;
	}
	return (-1);
}

char	*ft_str_cut(char *str, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		i++;
	}
	return (&str[i]);
}

char	*ft_str_first_values(char *str, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_dict_value(char *str)
{
	int	len;
	int	lvl;
	int	mod;
	int	less;

	len = ft_strlen(str);
	lvl = ft_get_lvl(str);
	mod = len % 3;
	less = mod;
	if (mod == 0)
		less += 3;
	if (lvl == 1)
	{
		if (mod == 0)
			less = 1;
		if (mod == 2)
			less = 0;
		if (mod == 1)
			less = 1;
	}
	return (ft_get_number(len - less));
}

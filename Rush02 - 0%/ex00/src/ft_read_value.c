/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:14:02 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/28 21:08:34 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_number_not_found(char *str, t_dict *dict, int *arr, int *r)
{
	if (str[arr[0]] != 48)
	{
		if (arr[1] == 3)
		{
			find_and_print(ft_itoa(r[arr[0]] / 100), dict);
			find_and_print("100", dict);
		}
		else
		{
			find_and_print(ft_itoa(r[arr[0]]), dict);
		}
	}
}

int	ft_number_found(char **arr2, t_dict *dict, int *arr, int *r)
{
	if (arr[1] == 3)
	{
		find_and_print(ft_itoa(r[arr[0]] / 100), dict);
		find_and_print("100", dict);
	}
	else
	{
		if (arr2[0][arr[0]] != '0')
			find_and_print(&arr2[0][arr[0]], dict);
		if (arr[2] > 1)
			find_and_print(arr2[1], dict);
		return (-1);
	}
	return (0);
}

void	ft_printdigits(char *str, t_dict *dict, int lvl, char *num)
{
	int		*r;
	int		arr[3];
	char	*arr2[2];

	r = ft_digits(str);
	arr[0] = 0;
	arr[1] = ft_strlen(str);
	arr[2] = lvl;
	arr2[0] = str;
	arr2[1] = num;
	while (r[arr[0]] != -7)
	{
		if (find(&str[arr[0]], dict) != 0)
		{
			ft_number_not_found(str, dict, arr, r);
			arr[1]--;
		}
		else
		{
			if (ft_number_found(arr2, dict, arr, r) == -1)
				break ;
		}
		arr[0]++;
	}
}

char	*ft_print_firsts_digits(char *str, t_dict *dict, int lvl, char *send)
{
	int	len;

	len = ft_strlen(str);
	if (len % 3 != 0)
	{
		if (len % 3 == 1)
		{
			ft_str_first_values(send, 1);
			ft_printdigits(send, dict, lvl, ft_get_dict_value(str));
			str = ft_str_cut(str, 1);
		}
		else
		{
			ft_str_first_values(send, 2);
			ft_printdigits(send, dict, lvl, ft_get_dict_value(str));
			str = ft_str_cut(str, 2);
		}
		lvl--;
	}
	return (str);
}

void	ft_read_value(char *str, t_dict *dict)
{
	char	*send;
	int		lvl;
	int		nvl;
	int		i;	

	send = (char *) malloc(1);
	lvl = ft_get_lvl(str);
	ft_strcpy(send, str);
	str = ft_print_firsts_digits(str, dict, lvl, send);
	i = 0;
	lvl = ft_get_lvl(str);
	nvl = lvl;
	while (i < lvl)
	{
		ft_strcpy(send, str);
		ft_str_first_values(send, 3);
		ft_printdigits(send, dict, nvl, ft_get_dict_value(str));
		nvl--;
		if (ft_strlen(str) > 3)
		{
			str = ft_str_cut(str, 3);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:42:57 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/28 09:42:59 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*ft_getkey(int file_data)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
	{
		ft_put_error();
		return ("-1");
	}
	i = 0;
	read(file_data, c, 1);
	while (c[0] == '\n')
		read(file_data, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(file_data, c, 1);
		i++;
	}
	return (str);
}

char	*ft_getvalue(int file_data, char *c)
{
	int		i;
	char	*str;

	(str = malloc(sizeof(char) * 128));
	if (!str)
	{
		ft_put_error();
		return ("-1");
	}
	i = 0;
	while (c[0] != '\n' && i < 11)
	{
		str[i] = c[0];
		read(file_data, c, 1);
		i++;
	}
	return (str);
}

void	create_dict_malloc(int file_data, t_dict *dict, char *c)
{
	int			i;
	char		*aux;

	i = 0;
	while (i < DICT_LINES)
	{
		aux = ft_strdup(ft_getkey(file_data));
		dict[i].key = aux;
		read(file_data, c, 1);
		while (c[0] == ' ')
			read(file_data, c, 1);
		if (c[0] == ':')
			read(file_data, c, 1);
		while (c[0] == ' ')
			read(file_data, c, 1);
		aux = ft_strdup(ft_getvalue(file_data, c));
		dict[i].value = aux;
		i++;
	}
	free(aux);
}

t_dict	*process_file(char *file)
{
	int				file_data;
	char			c[1];
	t_dict			*dict;
	static t_dict	error[1];

	file_data = open(file, O_RDONLY);
	dict = malloc(sizeof(t_dict) * DICT_LINES + 1);
	if (file_data == -1)
	{
		ft_put_dict_error();
		error[0].key = "-1";
		return (error);
	}
	if (!dict)
	{
		ft_put_error();
		error[0].key = "-1";
		return (error);
	}
	create_dict_malloc(file_data, dict, c);
	close(file_data);
	return (dict);
}

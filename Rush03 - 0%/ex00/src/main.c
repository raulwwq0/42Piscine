/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:34:15 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/28 12:34:19 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	init_dict_path(char *dict_path)
{
	int		i;
	char	*dict_folder;

	dict_folder = "./dict/";
	i = 0;
	while (i < 9)
	{
		dict_path[i] = dict_folder[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	dict_path[100];

	if (argc < 2 || argc > 3)
	{
		ft_put_error();
		return (-1);
	}
	init_dict_path(dict_path);
	if (argc == 2)
	{
		ft_strcat(dict_path, "numbers.dict");
		check_valid_input(argv[1]);
	}
	if (argc == 3)
	{
		ft_strcat(dict_path, argv[1]);
		check_valid_input(argv[2]);
	}
	dict = process_file(dict_path);
	if (ft_strcmp(dict[0].key, "-1") != 0)
		ft_read_value(argv[1], dict);
}

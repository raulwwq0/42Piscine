/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:14:05 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/31 16:53:54 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	check_valid_header(t_map_data header)
{
	return ((header.empty_char != header.filled_char
			&& header.filled_char != header.obstacle_char
			&& header.obstacle_char != header.empty_char)
		&& header.rows > 0
		&& header.columns > 1);
}

int	check_valid_char(char c, t_map_data header)
{
	return (c == header.empty_char || c == header.obstacle_char
		|| c == header.filled_char);
}

int	check_valid_map_relegated(int file_data, t_map_data header,
						int *counts, char *c)
{
	if (header.rows > 1)
	{
		while (counts[0] < header.rows)
		{
			read(file_data, c, 1);
			if (!check_valid_char(c[0], header) && c[0] != '\n')
				return (-1);
			counts[1]++;
			if (c[0] == '\n')
			{
				counts[0]++;
				if (counts[1] > 1)
					return (-1);
				counts[1] = 0;
			}
		}
	}
	if (counts[0] < header.rows - 1)
		return (-1);
	return (0);
}

int	check_valid_map(int file_data, t_map_data header)
{
	char	c[1];
	int		counts[2];

	counts[0] = 0;
	counts[1] = 0;
	while (counts[0] < header.rows - 1)
	{
		read(file_data, c, 1);
		if (!check_valid_char(c[0], header) && c[0] != '\n')
			return (-1);
		counts[1]++;
		if (c[0] == '\n')
		{
			counts[0]++;
			if (counts[1] != header.columns)
				return (-1);
			counts[1] = 0;
		}
	}
	if (check_valid_map_relegated(file_data, header, counts, c) == -1)
		return (-1);
	return (0);
}

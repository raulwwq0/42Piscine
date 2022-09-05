/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:10:55 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/31 16:54:08 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_map_data	read_header(int file_data)
{
	char			buffer[100];
	int				i;
	char			c[1];
	t_map_data		header;

	i = 0;
	read(file_data, c, 1);
	while (c[0] != '\n')
	{
		buffer[i] = c[0];
		read(file_data, c, 1);
		i++;
	}
	i--;
	header.filled_char = buffer[i];
	buffer[i] = '\0';
	i--;
	header.obstacle_char = buffer[i];
	buffer[i] = '\0';
	i--;
	header.empty_char = buffer[i];
	buffer[i] = '\0';
	i--;
	header.rows = ft_atoi(buffer);
	return (header);
}

int	get_first_line_len(int file_data, t_map_data header)
{
	int		file_data_copy;
	int		line_len;
	int		n_count;
	char	c[1];

	file_data_copy = file_data;
	n_count = 0;
	line_len = 0;
	while (n_count < 1)
	{
		read(file_data_copy, c, 1);
		if (!check_valid_char(c[0], header) && c[0] != '\n')
		{
			return (0);
		}
		if (c[0] == '\n')
			n_count++;
		line_len++;
	}
	return (line_len);
}

t_map_data	process_map(char *str)
{
	int			map_data;
	t_map_data	header;

	map_data = open(str, O_RDONLY);
	if (map_data == -1)
	{
		header.rows = 0;
		close(map_data);
		return (header);
	}
	header = read_header(map_data);
	header.columns = get_first_line_len(map_data, header);
	if (header.columns == -1 || check_valid_map(map_data, header) == -1)
	{
		header.rows = 0;
		close(map_data);
		return (header);
	}
	close(map_data);
	return (header);
}

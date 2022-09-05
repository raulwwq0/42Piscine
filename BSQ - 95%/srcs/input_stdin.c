/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:05:40 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/31 18:01:09 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*ft_read_stdin(void)
{
	char	*buffer;
	char	c;
	int		size;

	size = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	ft_init_buffer(buffer, BUFFER_SIZE);
	while (read(0, &c, 1) > 0)
	{
		if (size >= BUFFER_SIZE)
			ft_memory_error();
		buffer[size] = c;
		size++;
	}
	if (size == 0)
		buffer[0] = 1;
	return (buffer);
}

char	**ft_process_header(
	char *buffer, char **board, t_map_data *mpdata, unsigned long int to)
{
	if (*(buffer + to - 1) > 31 && *(buffer + to - 2) > 31
		&& *(buffer + to - 3) > 31 && *(buffer + to) == '\n'
		&& *(buffer + to - 1) != *(buffer + to - 2)
		&& *(buffer + to - 1) != *(buffer + to - 3)
		&& *(buffer + to - 2) != *(buffer + to - 3))
	{
		mpdata->empty_char = *(buffer + to - 3);
		mpdata->obstacle_char = *(buffer + to - 2);
		mpdata->filled_char = *(buffer + to - 1);
		to = (unsigned long int)buffer + to - 3;
		while (is_number(*buffer) == 1 && (unsigned long int)buffer < to)
		{
			mpdata->rows *= 10;
			mpdata->rows += (*buffer) - '0';
			buffer++;
		}
		if ((unsigned long int)buffer != to)
			ft_map_error();
		board = malloc((mpdata->rows + 1) * sizeof(char *));
		if (!board)
			ft_memory_error();
	}
	else
		ft_map_error();
	return (board);
}

char	*ft_process_row(char *buffer, int from, t_map_data *map_data)
{
	char	*row;
	int		i;

	i = 0;
	row = malloc((map_data->columns + 1) * sizeof(char));
	if (!row)
		ft_memory_error();
	while (buffer[from + i] != '\n')
	{
		if (i > map_data->columns)
			ft_map_error();
		if (buffer[from + i] == map_data->empty_char
			|| buffer[from + i] == map_data->obstacle_char)
			row[i] = buffer[from + i];
		else
			ft_map_error();
		i++;
	}
	if (i <= map_data->columns)
		ft_map_error();
	row[i] = '\0';
	return (row);
}

char	**ft_process_buffer(char *buffer, t_map_data *m_data)
{
	t_buffer_counters	bf;
	char				**board;

	ft_init_buffcounters(&bf);
	while (bf.pos < BUFFER_SIZE)
	{
		if (bf.line_init == 0 && buffer[bf.pos] == '\n')
		{
			board = ft_process_header(buffer, board, m_data, bf.pos);
			bf.line_init = bf.pos + 1;
		}
		else if (bf.line_init > 0 && buffer[bf.pos] == '\n')
		{
			if (m_data->columns == 0)
				m_data->columns = bf.pos - 1 - bf.line_init;
			if (bf.index < m_data->rows)
				board[bf.index] = ft_process_row(buffer, bf.line_init, m_data);
			bf.line_init = bf.pos + 1;
			bf.index++;
		}
		bf.pos++;
	}
	if (bf.index != m_data->rows || buffer[bf.line_init] != '\0')
		ft_map_error();
	return (board);
}

char	**ft_input_stdin(t_map_data *map_data)
{
	char	*board_buffer;
	char	**board;

	map_data->rows = 0;
	map_data->columns = 0;
	board_buffer = ft_read_stdin();
	board = ft_process_buffer(board_buffer, map_data);
	free(board_buffer);
	board[map_data->rows] = NULL;
	return (board);
}

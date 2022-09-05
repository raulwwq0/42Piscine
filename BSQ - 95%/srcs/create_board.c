/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:46:11 by rauaguil          #+#    #+#             */
/*   Updated: 2022/09/01 08:46:13 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*create_row_relegated(char *row, int file_data, t_map_data header)
{
	char	c[1];
	int		i;

	i = 0;
	while (c[0] != EOF && c[0] != '\n' && i <= header.columns)
	{
		read(file_data, c, 1);
		if (!(check_valid_char(c[0], header) || c[0] == '\n'))
		{
			free(row);
			return (NULL);
		}
		if (c[0] == '\n')
			row[i] = '\0';
		else
			row[i] = c[0];
		i++;
	}
	if (c[0] == EOF || i > header.columns)
	{
		free(row);
		return (NULL);
	}
	c[0] = ' ';
	return (row);
}

char	*create_row(int row_size, int file_data, t_map_data header)
{
	char	*row;

	row = (char *) malloc(row_size);
	return (create_row_relegated(row, file_data, header));
}

char	**create_board_relegated(char **board, t_map_data header, int map_data)
{
	int		i;
	int		row_size;

	row_size = sizeof(char) * header.columns;
	i = 0;
	while (i < header.rows)
	{
		board[i] = create_row(row_size, map_data, header);
		if (board[i] == NULL)
		{
			ft_free_char_matrix(board, header);
			close(map_data);
			ft_print_msg("map error");
			return (NULL);
		}
		i++;
	}
	board[i] = "";
	close(map_data);
	return (board);
}

char	**create_board(t_map_data header, char *str)
{
	char	**board;
	int		map_data;

	map_data = open(str, O_RDONLY);
	if (map_data == -1 || header.rows == 0)
	{
		ft_print_msg("map error");
		return (NULL);
	}
	read_header(map_data);
	board = (char **) malloc(sizeof(char *) * header.rows * 2);
	return (create_board_relegated(board, header, map_data));
}

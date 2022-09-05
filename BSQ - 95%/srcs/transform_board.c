/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:42:41 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/31 18:12:33 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static void	ft_char_to_ints(char *str, int *row, char block)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == block)
			row[i] = 0;
		else
			row[i] = 1;
		i++;
	}
	row[i] = END_OF_ROW;
}

int	**ft_transform_board2(char **char_board, char block_char)
{
	int	i;
	int	num_rows;
	int	**int_board;
	int	len;

	i = 0;
	num_rows = 0;
	while (char_board[num_rows] != NULL)
		num_rows++;
	int_board = malloc((num_rows + 1) * sizeof(int *));
	if (!int_board)
		ft_memory_error();
	int_board[num_rows] = NULL;
	while (i < num_rows)
	{
		len = ft_str_len(char_board[i]);
		int_board[i] = malloc((len + 1) * sizeof(int));
		if (!int_board[i])
			ft_memory_error();
		ft_char_to_ints(char_board[i], int_board[i], block_char);
		i++;
	}
	return (int_board);
}

int	**ft_transform_board1(char **char_board, char block_char)
{
	int	i;
	int	num_rows;
	int	**int_board;
	int	len;

	i = 0;
	num_rows = 0;
	while (char_board[num_rows][0] != '\0')
		num_rows++;
	int_board = malloc((num_rows + 1) * sizeof(int *));
	if (!int_board)
		ft_memory_error();
	int_board[num_rows] = NULL;
	while (i < num_rows)
	{
		len = ft_str_len(char_board[i]);
		int_board[i] = malloc((len + 1) * sizeof(int));
		if (!int_board[i])
			ft_memory_error();
		ft_char_to_ints(char_board[i], int_board[i], block_char);
		i++;
	}
	return (int_board);
}

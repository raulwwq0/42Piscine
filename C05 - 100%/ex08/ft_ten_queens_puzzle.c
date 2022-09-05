/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:45:05 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/24 10:52:40 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	is_queen_at_risk(int board[][10], int at_x, int at_y)
{
	int	x;
	int	y;
	int	offsets[2];

	offsets[0] = at_y - at_x;
	offsets[1] = at_y + at_x;
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (x == at_x || y == at_y
				|| y == x + offsets[0] || y == -x + offsets[1])
				if (board[y][x])
					return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	clear_column(int board[][10], int x)
{
	int	index;

	index = 0;
	while (index < 10)
	{
		board[index++][x] = false;
	}
}

void	print_queen_position(int board[][10])
{
	int	y;
	int	column;

	y = 0;
	while (y < 10)
	{
		column = 0;
		while (column < 10)
		{
			if (board[y][column])
			{
				write(1, &"0123456789"[column], 1);
				break ;
			}
			column++;
		}
		y++;
	}
	write(1, "\n", 1);
}

bool	recursive_find(int board[][10], int x, int *result)
{
	int	y;

	if (x >= 10)
		return (true);
	y = 0;
	while (y < 10)
	{
		if (!is_queen_at_risk(board, x, y))
		{
			board[y][x] = true;
			if (recursive_find(board, x + 1, result))
			{
				*result += 1;
				print_queen_position(board);
			}
			board[y][x] = false;
		}
		y++;
	}
	return (false);
}

int	ft_ten_queens_puzzle(void)
{
	int	result;
	int	board[10][10];
	int	column;

	result = 0;
	column = 0;
	while (column++ < 10)
		clear_column(board, column - 1);
	recursive_find(board, 0, &result);
	return (result);
}

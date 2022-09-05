/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:42:28 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/30 09:42:31 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static void	ft_compute_histograms(int **board)
{
	int	i;
	int	j;

	i = 1;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != END_OF_ROW)
		{
			if (board[i][j] != 0 && board[i - 1][j] != 0)
				board[i][j] += board[i - 1][j];
			j++;
		}
		i++;
	}
}

t_square	ft_solve(int **board)
{
	int			i;
	t_square	square;
	t_square	best_square;

	best_square.length = 0;
	ft_compute_histograms(board);
	i = 0;
	while (board[i] != NULL)
	{
		square = ft_histogram_solve(board[i], i);
		if (square.length > best_square.length)
			best_square = square;
		i++;
	}
	return (best_square);
}

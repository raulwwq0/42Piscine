/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histogram_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:23:23 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/29 17:50:49 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_square	ft_assign_square(int x, int y, int length)
{
	t_square	square;

	square.origin_x = x;
	square.origin_y = y;
	square.length = length;
	return (square);
}

t_square	ft_create_square(void)
{
	t_square	square;

	square = ft_assign_square(0, 0, 0);
	return (square);
}

int	ft_find_valid_length(int *row, int x)
{
	int	length;
	int	max_len;

	length = 1;
	max_len = row[x];
	while (row[x] != END_OF_ROW && length <= max_len)
	{
		length++;
		x++;
		if (row[x] < max_len)
			max_len = row[x];
	}
	return (length - 1);
}

t_square	ft_histogram_solve(int *row, int y)
{
	int			x;
	int			tmp_length;
	t_square	square;

	x = 0;
	square = ft_create_square();
	while (row[x] != END_OF_ROW)
	{
		if (row[x] == 1 && square.length == 0)
			square = ft_assign_square(x, y, 1);
		else
		{
			tmp_length = ft_find_valid_length(row, x);
			if (square.length < tmp_length)
			{
				square = ft_assign_square(x, y - tmp_length + 1, tmp_length);
				if (square.length == y + 1)
					break ;
			}
		}
		x++;
	}
	return (square);
}

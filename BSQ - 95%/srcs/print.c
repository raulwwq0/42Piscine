/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:43:22 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/31 18:12:53 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_map_error(void)
{
	ft_print_msg(MAP_ERROR);
	exit(1);
}

void	ft_print_msg(char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		ft_putchar(msg[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_solution1(t_square square, char **str_board, char fill_char)
{
	int	y;
	int	x;

	y = 0;
	while (str_board[y][0] != '\0')
	{
		x = 0;
		while (str_board[y][x] != '\0')
		{
			if (x >= square.origin_x
				&& x < (square.origin_x + square.length)
				&& y >= square.origin_y
				&& y < (square.origin_y + square.length))
				ft_putchar(fill_char);
			else
				ft_putchar(str_board[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_print_solution2(t_square square, char **str_board, char fill_char)
{
	int	y;
	int	x;

	y = 0;
	while (str_board[y] != NULL)
	{
		x = 0;
		while (str_board[y][x] != '\0')
		{
			if (x >= square.origin_x
				&& x < (square.origin_x + square.length)
				&& y >= square.origin_y
				&& y < (square.origin_y + square.length))
				ft_putchar(fill_char);
			else
				ft_putchar(str_board[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

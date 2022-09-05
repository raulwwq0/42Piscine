/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:52 by rauaguil          #+#    #+#             */
/*   Updated: 2022/09/01 13:52:51 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	bsq_solver(t_map_data header, char **argv, int i)
{
	int			**board;
	char		**str_board;
	t_square	square;

	str_board = create_board(header, argv[i]);
	if (str_board != NULL)
	{
		board = ft_transform_board1(str_board, header.obstacle_char);
		square = ft_solve(board);
		ft_print_solution1(square, str_board, header.filled_char);
		ft_free_int_matrix(board);
		ft_free_char_matrix(str_board, header);
	}
}

void	bsq_solver_stdin(void)
{
	char		**str_board;
	int			**board;
	t_square	square;
	t_map_data	map_data;

	str_board = ft_input_stdin(&map_data);
	board = ft_transform_board2(str_board, map_data.obstacle_char);
	square = ft_solve(board);
	ft_print_solution2(square, str_board, map_data.filled_char);
	ft_free_int_matrix(board);
	ft_free_strmatrix(str_board);
}

int	main(int argc, char **argv)
{
	t_map_data	header;
	int			i;

	i = 1;
	if (argc == 1)
		bsq_solver_stdin();
	else
	{
		while (i < argc)
		{
			header = process_map(argv[i]);
			if (check_valid_header(header))
			{
				bsq_solver(header, argv, i);
			}
			else
				ft_print_msg("map error");
			i++;
			if (argc > 2 && i < argc)
				ft_putchar('\n');
		}
	}
	return (0);
}

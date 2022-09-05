/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:16:49 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/21 10:18:41 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

/* Check if a box with the same size exists in the same column or row.
 * With position / 4 we can choose the row. 
 * With position % 4 we can choose the column. */
int	check_box_already_exists(int board[4][4], int position, int size)
{
	int	i;

	i = 0;
	while (i < position / 4)
	{
		if (board[i][position % 4] == size)
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < position % 4)
	{
		if (board[position / 4][i] == size)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* Search for a bad argument input.
 * Return 1 if the arguments are incorrect. 
 * Return 0 if the arguments are correct. */
int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) != 31)
		return (1);
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] < '1' || argv[1][i] > '4')
				return (1);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 08:48:27 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/21 09:34:25 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Write a char in the standard output, using
 * write function. */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Print a string in the standard output char by 
 * char, using write function. */
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

/* Calc the string length using a while loop
 * Return the string length. */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*	Once we find a solution we need to print a format version
 *  of the board (print it like a square) in the console. */
void	print_solution(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(board[i][j] + '0');
			if (j != 3)
			{
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/* Take the string from argv[1] and place ir in the memory allocation
 * that we create in the main function using malloc.*/
void	save_argv_values(int *visibilities, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			visibilities[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:47 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/14 19:14:51 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prototype for the ft_putchar function*/
void	ft_putchar(char c);

void	print_top_bottom_row(int x, int position_x)
{
	if (position_x == 1 || position_x == x)
	{
		ft_putchar('o');
	}
	else
	{	
		ft_putchar('-');
	}
}

void	print_middle_row(int x, int position_x)
{
	if (position_x == 1 || position_x == x)
	{
		ft_putchar('|');
	}
	else
	{	
		ft_putchar(' ');
	}
}

/* Print the figure itself, using a different char depending
 * on the row position where it is placed. */
void	print_figure(int x, int y, int position_x, int position_y)
{
	if (position_y == 1 || position_y == y)
	{
		print_top_bottom_row(x, position_x);
	}
	else
	{
		print_middle_row(x, position_x);
	}
}

/* Print a rectangle using the numbers from the parameters as 
 * width (x) and height (y). 
 *
 * At the end of the first loop we need to reset the position 
 * x counter and create new line to place the next row*/
void	rush(int x, int y)
{
	int	position_x;
	int	position_y;

	position_x = 1;
	position_y = 1;
	if (x != 0 && y != 0)
	{
		while (position_y <= y)
		{
			while (position_x <= x)
			{
				print_figure(x, y, position_x, position_y);
				position_x++;
			}
			position_y++;
			position_x = 1;
			ft_putchar('\n');
		}
	}
}

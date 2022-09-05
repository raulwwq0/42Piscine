/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:16:23 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/13 19:02:03 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char i, char j, char k, bool last)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	if (!last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_number_checked(int i, int j, int k)
{
	bool	last_number;

	last_number = false;
	if (i == '7' && j == '8' && k == '9')
	{
		last_number = true;
	}
	ft_print(i, j, k, last_number);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '7')
	{
		while (j <= '8')
		{
			while (k <= '9')
			{		
				if (i != j && j != k && k != i)
				{
					ft_print_number_checked(i, j, k);
				}
				k++;
			}
			k = j++;
		}	
		j = i++;
	}
}

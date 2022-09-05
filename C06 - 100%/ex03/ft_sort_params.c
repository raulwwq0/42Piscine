/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:48:01 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/25 09:03:46 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	char	c;

	while (*str != '\0')
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			result = *s1 - *s2;
			break ;
		}
		s1++;
		s2++;
	}
	return (result);
}

void	ft_str_sort(char **argv, int size)
{
	int		index;
	bool	swapped;

	index = 1;
	while (true)
	{
		index = 1;
		swapped = false;
		while (index < size)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
			{
				ft_swap(&argv[index], &argv[index + 1]);
				swapped = true;
			}
			index++;
		}
		if (!swapped)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	if (argc > 2)
		ft_str_sort(argv, argc - 1);
	index = 0;
	while (++index < argc)
	{
		ft_putstr(argv[index]);
		ft_putstr("\n");
	}
}

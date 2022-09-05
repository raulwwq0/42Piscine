/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:02:27 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/23 16:26:02 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_base_valid(char *str)
{
	char	*curr;
	int		i;
	int		j;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (false);
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	i = 0;
	while (i < curr - str)
	{
		j = i + 1;
		while (j < curr - str)
			if (str[i] == str[j++])
				return (false);
		i++;
	}
	return (true);
}

void	ft_putnbr_base_recursive(int number, char *base, int base_len)
{
	if (number == -2147483648)
	{
		ft_putnbr_base_recursive(number / base_len, base, base_len);
		write(1, &(base[-(number % base_len)]), 1);
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursive(-number, base, base_len);
		return ;
	}
	if (number > base_len - 1)
		ft_putnbr_base_recursive(number / base_len, base, base_len);
	write(1, &(base[number % base_len]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!is_base_valid(base))
		return ;
	base_len = ft_strlen(base);
	ft_putnbr_base_recursive(nbr, base, base_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:50:40 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/23 09:28:07 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

bool	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

int	check_base(char *base)
{
	char	*base_copy;
	int		i;
	int		j;

	base_copy = base;
	i = 0;
	j = 0;
	if (base == 0 || ft_strlen(base) <= 1)
		return (1);
	while (*base_copy != '\0')
	{
		if (is_space(*base_copy) || *base_copy == '+' || *base_copy == '-')
			return (1);
		base_copy++;
	}
	while (i < base_copy - base)
	{
		j = i + 1;
		while (j < base_copy - base)
			if (base[i] == base[j++])
				return (1);
		i++;
	}
	return (0);
}

int	resolve_base(char *base, char curr)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == curr)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;
	int	minus;

	if (check_base(base) == 1)
		return (0);
	base_len = ft_strlen(base);
	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (resolve_base(base, *str) != -1)
	{
		result *= base_len;
		result += resolve_base(base, *str);
		str++;
	}
	return (result * minus);
}

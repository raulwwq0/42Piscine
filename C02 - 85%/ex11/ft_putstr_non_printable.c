/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:49:24 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/17 08:56:24 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_char_printable(char c)
{
	return (c >= ' ' && c != 127);
}

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	current_char;

	index = 0;
	while (true)
	{
		current_char = str[index];
		if (current_char == '\0')
		{
			break ;
		}
		if (is_char_printable(current_char))
		{
			ft_putchar(current_char);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current_char / 16]);
			ft_putchar("0123456789abcdef"[current_char % 16]);
		}
		index++;
	}
}

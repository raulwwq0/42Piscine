/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:58:42 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/16 08:44:40 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strlowcase(char *str)
{
	int		index;
	char	current_char;

	index = 0;
	while (true)
	{
		current_char = str[index];
		if (current_char == '\0')
		{
			break ;
		}
		if (current_char >= 'A' && current_char <= 'Z')
		{
			str[index] = current_char + 32;
		}
		index++;
	}
	return (str);
}

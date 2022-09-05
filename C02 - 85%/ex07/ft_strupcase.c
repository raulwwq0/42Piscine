/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:50:31 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/16 08:45:04 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strupcase(char *str)
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
		if (current_char >= 'a' && current_char <= 'z')
		{
			str[index] = current_char - 32;
		}
		index++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:25:26 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 18:49:37 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if (*str < ' ' && *str != 127)
		{
			result = 0;
			break ;
		}
		str++;
	}
	return (result);
}

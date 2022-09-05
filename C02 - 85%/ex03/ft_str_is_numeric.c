/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:06:42 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 17:28:13 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			result = 0;
			break ;
		}
		str++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:24:49 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 17:25:17 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			result = 0;
			break ;
		}
		str++;
	}
	return (result);
}

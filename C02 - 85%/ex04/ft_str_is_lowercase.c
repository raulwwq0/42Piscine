/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:28 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 17:25:25 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
		{
			result = 0;
			break ;
		}
		str++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:06:52 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/18 18:24:42 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_copy;
	char	*to_find_copy;

	if (*to_find == '\0')
		return (str);
	str_copy = str;
	to_find_copy = to_find;
	while (true)
	{
		if (*to_find_copy == '\0')
			return ((char *)(str_copy - (to_find_copy - to_find)));
		if (*str_copy == *to_find_copy)
			to_find_copy++;
		else
			to_find_copy = to_find;
		if (*str_copy == '\0')
			break ;
		str_copy++;
	}
	return (0);
}

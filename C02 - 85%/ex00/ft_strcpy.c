/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:44:05 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 16:13:32 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (*src != '\0')
	{
		dest[index] = *src;
		src++;
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

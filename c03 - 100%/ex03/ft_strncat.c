/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:50:44 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/18 08:54:02 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*default_dest;
	unsigned int	index;

	default_dest = dest;
	index = 0;
	while (*default_dest != '\0')
	{
		default_dest++;
	}
	while (index < nb && *src != '\0')
	{
		*default_dest = *src;
		default_dest++;
		src++;
		index++;
	}
	*default_dest = '\0';
	return (dest);
}

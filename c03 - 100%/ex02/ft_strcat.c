/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:56:15 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/17 17:17:20 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char			*default_dest;

	default_dest = dest;
	while (*default_dest != '\0')
	{
		default_dest++;
	}
	while (*src != '\0')
	{
		*default_dest = *src;
		default_dest++;
		src++;
	}
	*default_dest = '\0';
	return (dest);
}

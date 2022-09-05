/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:46:08 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/28 18:00:17 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			result = *s1 - *s2;
			break ;
		}
		s1++;
		s2++;
	}
	return (result);
}

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:45:37 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/17 16:53:49 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				result;
	unsigned int	index;

	result = 0;
	index = 0;
	while (index < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			result = *s1 - *s2;
			break ;
		}
		s1++;
		s2++;
		index++;
	}
	return (result);
}

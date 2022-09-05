/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:30:04 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/18 15:51:02 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_ptr_length(char *ptr)
{
	unsigned int	count;

	count = 0;
	while (ptr[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dest_copy;
	char			*src_copy;
	unsigned int	dest_copy_length;
	unsigned int	size_left;

	dest_copy = dest;
	src_copy = src;
	size_left = size;
	while (size_left-- != 0 && *dest_copy != '\0')
		dest_copy++;
	dest_copy_length = dest_copy - dest;
	size_left = size - dest_copy_length;
	if (size_left == 0)
		return (dest_copy_length + ft_ptr_length(src));
	while (*src != '\0')
	{
		if (size_left > 1)
		{
			*dest_copy++ = *src;
			size_left--;
		}
		src++;
	}
	*dest_copy = '\0';
	return (dest_copy_length + (src - src_copy));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:55:24 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/24 19:19:13 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			while (*argv[i] != '\0')
			{
				write(1, argv[i], 1);
				argv[i]++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

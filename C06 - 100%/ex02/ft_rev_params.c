/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:25:06 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/24 19:26:16 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	if (argc > 1)
	{
		while (i >= 1)
		{
			while (*argv[i] != '\0')
			{
				write(1, argv[i], 1);
				argv[i]++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
}

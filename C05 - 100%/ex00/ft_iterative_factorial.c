/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:39:38 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/24 12:14:00 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb == 0)
	{
		return (1);
	}
	if (nb > 0)
	{
		result = 1;
		i = 1;
		while (i <= nb)
		{
			result *= i;
			i++;
		}
		return (result);
	}
	return (0);
}

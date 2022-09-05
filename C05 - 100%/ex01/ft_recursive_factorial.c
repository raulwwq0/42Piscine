/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:04:09 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/23 19:44:21 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc(int factorial, int nb)
{
	factorial *= nb--;
	if (nb > 0)
	{
		return (calc(factorial, nb));
	}
	return (factorial);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	return (calc(1, nb));
}

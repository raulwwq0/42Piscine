/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:32:46 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/15 09:37:59 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	aux;

	index = 0;
	while (index < size / 2)
	{
		aux = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = aux;
		index++;
	}
}

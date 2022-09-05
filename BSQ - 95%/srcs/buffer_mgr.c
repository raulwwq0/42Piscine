/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:42:51 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/31 18:01:21 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_init_buffer(char *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[i] = '\0';
		i++;
	}
}

void	ft_init_buffcounters(t_buffer_counters *bf)
{
	bf->pos = 0;
	bf->index = 0;
	bf->line_init = 0;
}

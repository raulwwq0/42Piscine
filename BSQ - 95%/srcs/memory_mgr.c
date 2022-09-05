/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mgr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:42:17 by iperez-r          #+#    #+#             */
/*   Updated: 2022/08/31 18:07:56 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_free_int_matrix(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_char_matrix(char **matrix, t_map_data header)
{
	int	i;

	i = 0;
	while (i < header.rows - 1)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
}

// son casi iguales
void	ft_free_strmatrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// TODO: mirar si cero es correcto
void	ft_memory_error(void)
{
	exit(1);
}

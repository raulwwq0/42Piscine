/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:04:59 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/31 16:51:48 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_TYPES_H
# define CUSTOM_TYPES_H

typedef struct s_map_data
{
	int		rows;
	int		columns;
	char	empty_char;
	char	obstacle_char;
	char	filled_char;
}	t_map_data;

typedef struct s_square
{
	int	origin_x;
	int	origin_y;
	int	length;
}	t_square;

typedef struct s_buffer_counters
{
	unsigned long int	pos;
	int					index;
	int					line_init;
}	t_buffer_counters;

#endif

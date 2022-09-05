/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:10:43 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/27 13:40:10 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_put_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_put_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauaguil <rauaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:45:50 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/16 08:54:16 by rauaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_transform_char(char *c, bool to_upper)
{
	if (!to_upper)
	{
		if (*c >= 'A' && *c <= 'Z')
		{
			*c = *c + 32;
		}
	}
	else
	{
		if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 32;
		}
	}
}

bool	is_char_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool	is_char_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

void	check_and_capitalize(char *curr_char, bool *in_word, bool *skip_word)
{
	bool	first_letter;

	first_letter = false;
	if (!*in_word)
	{
		if (is_char_numeric(*curr_char))
			*skip_word = true;
		else if (is_char_alpha(*curr_char) && !*skip_word)
		{
			*in_word = true;
			first_letter = true;
		}
	}
	ft_transform_char(curr_char, false);
	if (*in_word)
		ft_transform_char(curr_char, first_letter);
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	char	*current_char;
	bool	in_word;
	bool	skip_word;

	index = 0;
	in_word = false;
	skip_word = false;
	current_char = &str[index];
	while (*current_char != '\0')
	{
		current_char = &str[index];
		check_and_capitalize(current_char, &in_word, &skip_word);
		if (!(is_char_alpha(*current_char) || is_char_numeric(*current_char)))
		{
			in_word = false;
			skip_word = false;
		}
		index++;
	}
	return (str);
}

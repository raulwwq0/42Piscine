/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:20:07 by rauaguil          #+#    #+#             */
/*   Updated: 2022/08/28 21:46:56 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define DICT_LINES 41

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;
void		ft_putchar(char c);
int			ft_atoi(char *str);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
char		*ft_getnb(int fd);
char		*ft_getval(int fd, char *c);
t_dict		*process_file(char *file);
int			find(char *key, t_dict *dict);
int			find_and_print(char *key, t_dict *dict);
void		ft_put_error(void);
void		ft_put_dict_error(void);
char		*check_valid_input(char *str);
char		*ft_get_number(int nvl);
int			ft_get_lvl(char *str);
char		*ft_get_dict_value(char *str);
char		*ft_str_cut(char *str, int num);
char		*ft_str_first_values(char *str, int num);
char		*ft_strcpy(char *dest, char *src);
void		ft_putnbr(int nb);
int			ft_power(int nb, int power);
int			*ft_digits(char *str);
void		ft_printdigits(char *str, t_dict *dict, int lvl, char *num);
void		ft_read_value(char *str, t_dict *dict);
int			nbr_len(int nbr);
int			ft_div(int len);
char		*ft_itoa(int nbr);
int			ft_nbrlen(int nbr);
int			ft_strlen(char *str);
char		*ft_print_firsts_digits(char *str, t_dict *dict,
				int lvl, char *send);
int			ft_case_zero_alone(char *str, int *tab, int i);
int			ft_number_found(char **arr2, t_dict *dict, int *arr, int *r);
void		ft_number_not_found(char *str, t_dict *dict, int *arr, int *r);

#endif
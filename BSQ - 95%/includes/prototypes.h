/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:05:31 by rauaguil          #+#    #+#             */
/*   Updated: 2022/09/01 13:59:22 by iperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int			is_number(char c);
char		*ft_strcat(char *dest, char *src);
int			check_valid_char(char c, t_map_data header);
int			check_valid_map(int file_data, t_map_data header);
int			check_valid_header(t_map_data header);
t_map_data	process_map(char *str);
char		**create_board(t_map_data header, char *str);
void		ft_putchar(char c);
char		**ft_process_header(
				char *buffer, char **board, t_map_data *mpdata,
				unsigned long int to
				);
t_square	ft_histogram_solve(int *row, int y);
t_square	ft_solve(int **board);
int			ft_str_len(char *c);
int			ft_array_len(int **array);
int			**ft_transform_board1(char **board, char block_char);
int			**ft_transform_board2(char **board, char block_char);
void		ft_free_int_matrix(int **matrix);
void		ft_free_strmatrix(char **matrix);
void		ft_free_char_matrix(char **matrix, t_map_data header);
void		ft_print_solution1(
				t_square square, char **str_board, char fill_char
				);
void		ft_print_solution2(
				t_square square, char **str_board, char fill_char
				);
void		ft_print_msg(char *msg);
void		ft_memory_error(void);
void		ft_init_buffer(char *array, int len);
char		**ft_input_stdin(t_map_data *map_data);
void		ft_map_error(void);
void		ft_init_buffcounters(t_buffer_counters *bf);
int			ft_atoi(const char *str);
t_map_data	read_header(int file_data);

#endif

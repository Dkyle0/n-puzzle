/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:48:37 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:28:14 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
# define N_PUZZLE_H

# define INVALID_INDEX -1
# define BUFF_SIZE 8

//	Ускорение А*
# define H_LIM 19

//	Прыжки
# define DEEP_LEN 6

//	Режимы алгоритмов
# define IDA 0
# define A_STAR 1
# define GREEDY_JUMP 2
# define GREEDY 3
# define UNIFORM 4

//	Типы эвристик
# define EASY_H 'e'
# define MANH_H 'm'
# define LINEAR_H 'l'

//	Режимы финальных карт
# define CLASSIC 0
# define SNAIL 1
# define SNAKE 2

# include "visual.h"
# include <time.h>
# include <unistd.h>
# include <string.h>

void		create_random(int *nbr, t_all *all);
int			check_unic(t_all *all, int lc);
int			cu2(t_all *all, int i_c1, int one_0);
int			check_line(int *max, int lc);
void		check_nbr_line(int *imap, int ir);
void		cloxer(t_all *all);
int			read_file(char const *argv[], t_all *all);
void		read_input(t_all *all);
char		**malloc_map(int all_line);
int			move2(t_all *all, int lc);
void		free_m(char **res, int a);
void		free_p1x(char **res, int i);
int			test(int *now, int *target, t_all *all);
int			summ_h(t_all *all, char flag);
int			is_target_in_line(int *target, t_all *all);
int			is_conflict(int *target, int *now, t_all *all);
int			is_str_size(char *str);
int			is_digit_str(char *str);
int			is_re(char *str);
void		init_read(t_all *all, char const *argv[], int *lc);
void		init_ks(int *i, int *ir, int *ss);
int			line_count(char const *argv[]);
void		m_generator(t_all *all, const char *option);
void		free_p1x(char **res, int i);
int			find(int *imap, int ir);
void		print_int_i(int imi, int *imap);
int			get_next_line_n(const int fd, char **line);
int			ret_ks(int *imap, int ir);
void		ks_if_end(int *max, int *ir, int imi, char **re);
void		simbol_in_str(char **map, int i, int imi);
char		**strsplit(char const *s, char c);
int			word_n(char *s, char c);

int			get_next_line(const int fd, char **line);

int			find_zero_index(int *map, int len);
void		find_possible_moves(int	i_zero, int *dst, t_all *all);
int			compare_map(int *map0, int *map1, int len);
int			*create_def_map(int n, int len, int mode);
void		snail(int i0, int n, int k, int *map);
void		classic(int n, int *map);
void		snake(int n, int *map);
int			*create_map(int len);
void		map_copy(int *src, int *dst, int len);
void		np_close(t_all *all);
int			find_min_weight(int *move_weight);
int			vertex_jump(t_list *present_move, t_all *all, int deep, int *min_w);
int			manh_dist(int *now, int *target, t_all *all, int i);
int			manh_fh(int *now, int *target, t_all *all);
int			easy_fh(int *now, int *target, t_all *all);
int			is_loop(t_list *list0, t_list *list, t_all *all);
void		print_int_i(int imi, int *imap);
int			check_solv(int *start, int *target, t_all *all);
void		del_list(t_list *list0, t_all *all);
int			get_next_index(int *move_weight, int index, int min);
int			move_len(t_list *list);
int			list_in_open_list(t_list_a *list, t_all *all);
int			vertex_a(t_list_a *open_list, t_all *all);
void		move_next_a(int *map, int i_zero, int i_b);
int			a_star_algorithm(t_all *all);
int			closer(t_all *all, char *msg, int option);
void		print_solve(t_all *all);
void		connect_way(t_all *all);
void		snail(int i0, int n, int k, int *map);
int			greedy_hopping_algorithm(t_all *all);
int			draw_decor(t_all *all);
int			draw_boxes(time_t t, int i_zero, int i_moved, t_all *all);
void		vertex_a_end(t_list_a *open_list, t_all *all);

#endif

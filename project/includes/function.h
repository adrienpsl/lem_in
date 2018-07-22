/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_FUNCTION_H
# define LEM_IN_FUNCTION_H

# include "../all_includes.h"

/*
**    debugs
*/
void     print_tunnel_dll(t_dll_l room_link);
void     print_room(t_room room);
void     print_map(char* tab_room, size_t size_line);
void     print_cache_list(t_dll_l path_link);
void     print_line(char* tab_room, size_t size_line, int cur_line);
void     print_map_taken(char* tab_room, size_t size_line);
void     print_path_dll(t_dll_l link);
void	print_path_link(t_dll_l link);
void     print_list_dll_path(t_dll_l dll_path_link);
void print_path_map(char *tab_room, size_t size_line, size_t col);
void print_line_path(char *tab_room, size_t size_line);
void print_path_link_nb(t_dll_l link);
void print_line_first(char *tab_room, size_t size_line, int cur_line);
void print_finder(t_dll finder);
void print_path_dll_order(t_dll_l link);
void print_line_first_int(char *tab_room, size_t size_line, int cur_line);


t_best_path new_best_path(size_t nb_path);
t_move new_move(t_data data, t_b_path best_path, t_finder finder);
void manage_move(t_move move);

/*
**    explication
*/
int option_print_list(t_finder cache, t_dll list, char *explain);

/*
**    OBJ ========================================================
*/

/*
**    path
*/
//t_path new_path(int room, t_path prev);
t_dll_l new_path_link(int room, t_path prev, t_dll all_path, int size);
void print_path(t_path path);
void get_all_path(t_dll list_finder, t_map map, t_data data, t_cache cache);
void free_list_list_path(void *list_ptr);
t_dll copy_all_path_order(t_dll_l close_path_link);
t_dll_l     get_dll_by_path(t_path path);
t_map generate_path_map(t_dll room, t_dll path_lst);
size_t fill_path(t_finder cache, t_map map);
void find_best_path(t_map map, t_best_path best);
void print_path_map_2(t_map map);


/*
**    ALGO ========================================================
*/
void split_path(t_map map, t_finder finder, t_path current_path, int *res);
void destroy_cache(t_cache cache);

/*
**    SHORT ALGO
*/
t_move short_algo(t_cache cache, t_data data, t_map map);


/*
**    cache
*/
void init_cache(t_cache cache, t_data data);
void clean_woking(t_finder finder);

/*
**    start
*/
void generate_map(t_map map, int y);
void destroy_map(t_map map);

/*
**    lem
*/
t_lem new_lem();
void     free_lem(t_lem lem);

/*
**    finder
*/
int init_finder(t_finder finder, t_map map);

/*
**   PARSEUR  ========================================================
*/
void	lem_read_data(t_data data);
void 	get_tunnel(t_data data, t_get_utils utils);
void	get_room(t_data data, t_get_utils utils);
void	set_tunnel(t_data data, t_map map);

/*
**    paseur utils
*/
int		manage_comment(t_str_split split);
int		is_right_room(t_dll_l link, void *ptr_new_room);
void	check_err_room(t_get_utils utils);
void	get_size_map(t_data data, int x, int y);

/*
**    contruct ========================================================
*/
t_dll_l new_tunnel_link(char *c_room_1, char *c_room_2);
t_dll_l new_room_link(char *x, char *y, char *name);
t_lem	new_lem();
t_finder new_finder(t_data data, int new_room_start, t_map map, t_cache cache);
t_dll_l new_finder_link(t_data data, t_map map, int new_start_room, t_cache cache);

/*
**    destroy ========================================================
*/
void destroy_tunnel(void *ptr_tunnel);
void destroy_room(void *room_ptr);
void destroy_lem(t_lem *lem);
void destroy_finder(t_finder finder);

void destroy_room_list(t_dll room_list);

#endif

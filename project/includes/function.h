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


/*
**    explication
*/
int option_print_list(t_cache cache, t_dll list, char *explain);

/*
**    OBJ ========================================================
*/

/*
**    path
*/
//t_path new_path(int room, t_path prev);
t_dll_l new_path_link(int room, t_path prev, t_dll all_path, int size);
void print_path(t_path path);
void     get_all_path(t_cache cache, t_map map);
void free_list_list_path(void *list_ptr);
t_dll copy_all_path_order(t_dll_l close_path_link);
t_dll_l     get_dll_by_path(t_path path);


/*
**    ALGO ========================================================
*/
void split_path(t_map map, t_cache cache, t_path current_path, int *res);
void destroy_cache(t_cache cache);

/*
**    cache
*/
void init_cache(t_cache cache, t_data data);
void clean_woking(t_cache cache);

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
**    exit
*/
void destroy_room_list(t_dll room_list);

#endif //LEM_IN_FUNCTION_H

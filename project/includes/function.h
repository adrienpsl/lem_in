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
**    debug
*/
void     print_tunnel_dll(t_dll_l room_link);
void     print_room(t_room room);
void     print_map(t_tab_room tab_room, size_t size_line);
void     print_cache_list(t_dll_l path_link);
void     print_line(t_tab_room tab_room, size_t size_line, int cur_line);
void     print_map_taken(t_tab_room tab_room, size_t size_line);

/*
**    OBJ ========================================================
*/

/*
**    path
*/
//t_path new_path(int room, t_path prev);
t_dll_l new_path_link(int room, t_path prev, t_dll all_path, int size);


/*
**    ALGO ========================================================
*/
void binarie_line(t_map map, t_cache cache, t_path current_path);

/*
**    cache
*/
void init_cache(t_cache cache, t_data data);
void clean_woking(t_cache cache);


/*
**    lem
*/
t_lem new_lem();
void     free_lem(t_lem lem);

/*
**   PARSEUR  ========================================================
*/
t_get_data_00 lem_read_line( );
void	get_coord_room(t_getter get);
void 	get_tunnel(t_getter get);
void	set_tab_tunnel(t_getter get);

/*
**    paseur utils
*/
int		manage_comment(t_str_split split);
int		is_right_room(t_dll_l link, void *ptr_new_room);
void	check_err_room(t_get_data data);
void	get_size_map(t_get_data data, int x, int y);


/*
**    exit
*/
void destroy_room_list(t_dll room_list);

#endif //LEM_IN_FUNCTION_H

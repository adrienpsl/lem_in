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

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

#include "getter.h"
#include "../libft/include/dll_header.h"
#include "struct_min.h"

/*
**    change type ========================================================
*/
typedef t_get_data_00 t_data_00;
typedef t_data_00 *t_data;

/*
**    algo ========================================================
*/
typedef struct		s_algo_00
{
	t_dll 	working_path;
	t_tab_room map;
	size_t y_map;
	t_room end;
} 					t_algo_00;
typedef t_algo_00 *t_algo;

/*
**    lem ========================================================
*/
typedef struct		s_lem
{
	t_data_00 data;
	t_algo_00 algo;
}					t_lem_00;
typedef t_lem_00 *t_lem;











t_dll_l new_tunnel_link(char *room_1, char *room_2);
void     destroy_tunnel(void *ptr_tunnel);

void     destroy_room(void* room_ptr);
t_dll_l new_room_link(char *x, char *y, char *name);






/*
**    construct ================================================================
*/
void  destroy_lem(t_lem *lem);
t_lem new_lem();

/*
**    method ===================================================================
*/


/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/


#endif

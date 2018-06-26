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

/*
**    change type ========================================================
*/
typedef t_get_data_00 t_data_00;
typedef t_data_00 *t_data;

/*
**    struct ========================================================
*/

typedef struct		s_lem_ptr_00
{
	void	*ptr;
} 					t_lem_ptr_00;
typedef t_lem_ptr_00 *t_lem_ptr;

typedef struct		s_tunnel_00
{
	char *room_1;
	char *room_2;
} 					t_tunnel_00;
typedef t_tunnel_00 *t_tunnel;

#define PATH 1
#define TAKEN 2
typedef struct		s_room_00
{
	int x;
	int y;
	char *name;
	int state;
	t_dll l_tube;
} 					t_room_00;
typedef t_room_00 *t_room;

typedef struct		s_path_00
{
	int size;
	struct		s_path_00 *prev;
	t_room 		room;
} 					t_path_00;
typedef t_path_00 *t_path;


typedef struct		s_algo_00
{
	t_dll	all_path;
	t_path 	working_path;
	t_room end;
} 					t_algo_00;
typedef t_algo_00 *t_algo;

/*
**    lem
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

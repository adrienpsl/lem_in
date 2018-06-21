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

# include "all_includes.h"
#include "../libft/include/dll_header.h"


/*
**    struct ========================================================
*/

/*
**    lem
*/
typedef struct		s_lem
{

}					*t_lem;

typedef struct		s_tunnel_00
{
	char *room_1;
	char *room_2;
} 					t_tunnel_00;
typedef t_tunnel_00 *t_tunnel;



typedef struct		s_room_00
{
	int x;
	int y;
	char *name;
	t_dll l_tube;
} 					t_room_00;
typedef t_room_00 *t_room;


t_dll_l new_tunnel_link(char *room_1, char *room_2);
void     destroy_tunnel(t_tunnel *ptr_tunnel);

void     destroy_room(t_room room);
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

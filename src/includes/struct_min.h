/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_min.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_MIN_H
# define LEM_IN_STRUCT_MIN_H

typedef struct		s_room_00
{
	int x;
	int y;
	int nb;
	int type;
	char *name;
} 					t_room_00;
typedef t_room_00 *t_room;

typedef struct		s_tunnel_00
{
	t_room room_1;
	t_room room_2;
} 					t_tunnel_00;
typedef t_tunnel_00 *t_tunnel;

typedef struct		s_path_00
{
	int 	room;
	int		size;
	int		is_full;
	char 	*name_room;
	struct s_path_00 *prev;
} 					t_path_00;
typedef t_path_00 *t_path;

typedef struct s_map_00
{
	char *map;
	size_t size;
	size_t col;
	size_t line;
} t_map_00;

typedef t_map_00 *t_map;


#endif

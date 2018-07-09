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

#ifndef LEM_IN_STRUCT_ALGO_H
#define LEM_IN_STRUCT_ALGO_H

#include "../libft/include/dll_header.h"
#include "struct.h"

typedef struct		s_cache_algo_00
{
	t_dll all_path;
	t_dll close_path;
	int end_room;
	int start_room;

} 					t_cache_algo_00;
typedef t_cache_algo_00 *t_cache_algo;


typedef struct s_cache_00
{
	t_dll working_path;
	t_dll new_path;
	t_dll all_path;
	t_dll close_path;
	int end_room;
	int start_room;
	char *taken_room;
	int option;
} t_cache_00;

typedef t_cache_00 *t_cache;

typedef struct s_algo_00
{
	t_cache_00 cache;
	t_dll all_path;
	t_map_00 map;
	t_room end;
} t_algo_00;

typedef t_algo_00 *t_algo;

#endif //LEM_IN_STRUCT_ALGO_H

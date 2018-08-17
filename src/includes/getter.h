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

#ifndef GETTER_H
# define GETTER_H
#include "all_includes.h"
/*
**    data
*/
typedef struct		s_data_00
{
	t_dll room;
	t_dll tunnel;
	int start_room;
	int end_room;
	int x;
	int y;
	int nb_fourmis;
	int lim;
} 					t_data_00;
typedef t_data_00 *t_data;


/*
**    utils
*/
typedef struct		s_get_utils_00
{
	char *line;
	int fd;
	int type_salle;
} 					t_get_utils_00;
typedef t_get_utils_00 *t_get_utils;


/*
**    getter
*/
typedef struct		s_getter_00
{
	t_data data;
	t_get_utils_00 utils;
} 					t_getter_00;
typedef t_getter_00 *t_getter;

#endif
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

#include "../includes/all_includes.h"

t_debug_struct DEBUG;

t_debug_struct set_debug()
{
	t_debug_struct db;

	db = ft_0_new_memory(sizeof(t_debug_struct_00));
	(void) "  set les demandes de debug  ";
	//	db->parseur = TRUE;
	//	db->print_err = TRUE;
	//	db->map_tunnel = TRUE;
	//	db->print_split = TRUE;
	//	db->map_path = TRUE;
	//	db->final_path = TRUE;
//	db->little = TRUE;

	(void) "  set le fichier a check  ";
		db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2_test";
	//		db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/big";
//	db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/map (5).txt";
	//		db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/hard";
	//	db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/big_2";


	DEBUG = db;
	return (db);
}



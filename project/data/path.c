///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_atoi.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
///*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../all_includes.h"
//
//
//
//// ajouter ca dans la lib,
//// refaire belle ma lib
//void add_ptr_dll(t_dll_l link, t_dll list)
//{
//	t_dll_l ptr_link;
//
//	ptr_link = new_dll_l_ptr(link->content);
//	dll_add(ptr_link, list);
//}
//
//// une fois un pass trouver je decompose tout les chemin qui depende de lui
//// je fait 3 finder qui parte de start ou end en fontion de la ou il y a le moins
//// de place // si je le fais en bianire et avec seulement les petit chemin je pense c'est good?
//// si 1000 room --> et que 50 room entre les deux :
//
//int has_taken_this_room(t_path path, int name, t_finder finder)
//{
//	(void)path;
//	if (finder->taken_room[name])
//		return (FALSE);
//	return (TRUE);
//
////		while (path)
////		{
////			if (line == path->room)
////				return (FALSE);
////			path = path->prev;
////		}
////		return (TRUE);
//}
//
//void split_path(t_map map, t_finder finder, t_path current_path, int *res)
//{
//	char *line_room;
//	t_dll_l path_link;
//	size_t col;
//
//	line_room = map->map + (current_path->room * map->col);
//	col = 0;
//	res ? *res = 0 : (void) 1;
//	while (col < map->col)
//	{
//		res ? *res = 1 : (void) 1;
//		if (line_room[col]
////			&&
////			has_taken_this_room(current_path, col, finder)
//		 )
//		{
//			path_link = new_path_link(col, current_path, finder->all_path,
//									  current_path->size + 1);
//
//			//			print_path(path_link->content);
//
//			add_ptr_dll(path_link, finder->new_path);
////			if (col != (size_t) finder->end_room)
////				finder->taken_room[col] = 1;
//
//			//			print_line(map_line + i, map->line, i);
//		}
//		++col;
//	}
//	//		print_line(finder->taken_room, map->line, 25);
//}

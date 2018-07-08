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

#include "../all_includes.h"

void print_cache_list(t_dll_l path_link)
{
	t_path path;

	path = path_link->content;

	printf("%c <-- ", path->prev->room + 'A');
	printf("%d - ", path->size);
	printf("%c\n", path->room + 'A');
}

void print_path_link(t_dll_l link)
{
	t_path path;

	path = link->content;
	printf("%c - ", path->room + 'A');
}

void print_path_link_nb(t_dll_l link)
{
	t_path path;

	path = link->content;
	printf("%d - ", path->room);
}

void print_list_dll_path(t_dll_l dll_path_link)
{
	t_dll list;

	list = dll_path_link->content;
	dll_func_where(list, print_path_link);
}

void print_path(t_path path)
{
	path = path->prev;
	while (path->prev)
	{
		printf("%c %d -- ", path->room + 'A', path->size);
		path = path->prev;
	}
	printf(" \n");
}

void print_path_dll(t_dll_l link)
{
	print_path(link->content);
}


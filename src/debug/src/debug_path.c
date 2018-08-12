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

#include "../../includes/all_includes.h"

void print_cache_list(t_dll_l path_link)
{
	t_path path;

	path = path_link->content;

	printf("%c <-- ", path->prev->room + 'A');
	printf("%d - ", path->size);
	printf("%c\n", path->room + 'A');
}

void print_path_link(void *link)
{
	t_path path;

	path = link;
	printf("%d-", path->room + 1);
}

void print_path_link_nb(t_dll_l link)
{
	t_path path;

	path = link->content;
	printf("%d - ", path->room);
}


void print_path(t_path path)
{
	//	path = path->prev;
	//	while (path->prev)
	while (path)
	{
		printf("%c %d -- ", path->room + 'A', path->size);
		path = path->prev;
	}
	printf(" \n");
}

void print_path_dll(void *link)
{
	print_path(link);
}

void print_path_dll_order(void *link)
{
	t_path path;
	size_t i;
	size_t ii;

	path = link;
	i = 0;
	while (path)
	{
		path = path->prev;
		i++;
	}
	i--;
	while (i)
	{
		ii = 0;
		path = link;
		while (ii < i)
		{
			path = path->prev;
			++ii;
		}
		printf("%c %d -- ", path->room + 'A', path->size);
		--i;
	}
	path = link;
	printf("%c %d -- ", path->room + 'A', path->size);
	printf(" \n");
}
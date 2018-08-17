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

/*
**    print start
*/


void print_name(int a)
{
	int i;

	i = 'A';
	ft_printf(" [[ ");
	while (i < a + 'A')
	{
		ft_printf("%2c ", i);
		++i;
	}
	ft_printf("]]\n");
}

void print_line_first(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name(size_line);
	ft_printf("%2d  ", +cur_line);
	while (i < size_line)
	{
		ft_printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	ft_printf("\n\n");
}

void print_name_int(int a)
{
	int i;

	i = 0;
	ft_printf("[[ ");
	while (i <= a)
	{
		ft_printf("%2d ", i);
		++i;
	}
	ft_printf("]]\n");
}

void print_line_first_int(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name_int(size_line);
	ft_printf("%c  ", 'A' + cur_line);
	while (i < size_line)
	{
		ft_printf("%2c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	ft_printf("\n");
}

void print_line(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name(size_line);
	tab_room += size_line * cur_line;
	ft_printf("%c  ", 'A' + cur_line);
	while (i < size_line)
	{
		ft_printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	ft_printf("\n\n");
}

void print_map(char *tab_room, size_t size_line)
{
	size_t i;
	size_t line;
	int letter;
	size_t lim;

	i = 0;
	line = 0;
	letter = 'B';
	lim = size_line * size_line;

	print_name(size_line);
	ft_printf("\nA   ");
	while (i < lim)
	{
		ft_printf("%2c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line && i < lim)
		{
			ft_printf(" \n%c   ", letter);
			letter++;
			line = 0;
		}
	}
	ft_printf("\n");
}

/*
**    MAP
*/

void print_line_path(char *tab_room, size_t size_line)
{
	size_t i;

	i = 1;

	ft_printf("[[ ");
	while (i < size_line)
	{
		ft_printf("%zu ", i);
		++i;
	}
	ft_printf("]] \n   ");
	i = 0;
	while (i < size_line)
	{
		ft_printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	ft_printf("\n");
}

void print_path_map(char *tab_room, size_t size_line, size_t col)
{
	size_t i;
	size_t line;
	size_t lim;
	size_t counter;

	i = 0;
	line = 0;
	lim = size_line * col;
	counter = 2;
	ft_printf("----> map all path \n  ");
	print_name(size_line);
	ft_printf("   1  ");
	while (i < lim)
	{
		ft_printf("%2c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line && i < lim)
		{
			ft_printf(" \n %3lu  ", counter);
			line = 0;
			++counter;
		}
	}
	ft_printf("\n----\n");
}

void print_path_map_2(t_map map)
{
	ssize_t i;
	size_t col;
	ssize_t lim;
	size_t counter;

	i = 0;
	col = 0;
	lim = map->col * map->line;
	counter = 1;

	print_name(map->col);
	ft_printf("\n 0  ");
	while (i < lim - 1)
	{
		ft_printf("%c ", map->map[i] ? 'X' : '.');
		++i;
		++col;
		if (col == map->col)
		{
			ft_printf(" \n%2lu  ", counter);
			col = 0;
			++counter;
		}
	}
	ft_printf("\n");
}


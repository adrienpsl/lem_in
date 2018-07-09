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

/*
**    print start
*/


void print_name(int a)
{
	int i;

	i = 'A';
	printf("[[ ");
	while (i < a + 'A')
	{
		printf("%c ", i);
		++i;
	}
	printf("]]\n");
}


void print_line(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name(size_line);
	printf("%c  ", 'A' + cur_line);
	while (i < size_line)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	printf("\n\n");
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
	printf("\nA  ");
	while (i < lim)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line)
		{
			printf(" \n%c  ", letter);
			letter++;
			line = 0;
		}
	}
	printf("\n");
}

/*
**    MAP
*/

void print_line_path(char *tab_room, size_t size_line)
{
	size_t i;

	i = 1;

	printf("[[ ");
	while (i < size_line)
	{
		printf("%zu ", i);
		++i;
	}
	printf("]] \n   ");
	i = 0;
	while (i < size_line)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	printf("\n");
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

	print_name(size_line);
	printf("\n1  ");
	while (i < lim)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line)
		{
			printf(" \n%lu  ", counter);
			line = 0;
			++counter;
		}
	}
	printf("\n");
}


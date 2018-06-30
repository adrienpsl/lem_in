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
**    print map
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

void print_line(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name(size_line);
	printf("\n%c  ", 'A' + cur_line);
	while (i < size_line)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	printf("\n");
}
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

void print_finder_link(t_dll_l finder_link)
{
	t_finder finder;

	finder = finder_link->content;

	if (finder->working_path)
	{
		printf("working finder \n");
		dll_func(finder->working_path, print_path_dll);
	}
}

void print_finder(t_dll finder_list)
{
	t_finder finder;

	dll_func(finder_list, print_finder_link);
	if (finder_list->top)
	{
		finder = finder_list->top->content;
		if (finder->close_path)
		{
			printf("closed finder \n");
			dll_func(finder->close_path, print_path_dll_order);
		}
	}
	printf("------------------------------------------ \n");
}
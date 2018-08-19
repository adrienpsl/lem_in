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

#include "../../../ft_library_header.h"

void		destroy_str_split(t_str_split *split_ptr)
{
	t_str_split split;

	if (split_ptr == NULL)
		return ;
	if (*split_ptr != NULL)
	{
		split = *split_ptr;
		if (split->start != NULL && split->all)
			ft_free_split(&split->start);
		free(split);
	}
	*split_ptr = NULL;
}

t_str_split	new_str_split(char *str, char c)
{
	t_str_split str_split;

	str_split = ft_malloc_protect(sizeof(struct s_str_split));
	ft_memset(str_split, 0, sizeof(struct s_str_split));
	str_split->start = ft_strsplit(str, c);
	str_split->all = count_split(str_split->start);
	if (str_split->all)
		str_split_get(str_split);
	return (str_split);
}

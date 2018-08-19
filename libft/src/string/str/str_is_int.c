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

int	str_is_int(char *str, int *out)
{
	static int signe = 0;

	if (str == NULL)
		return (FAIL);
	if (is_all_number(str) == FAIL)
		return (FAIL);
	else
	{
		*out = ft_atoi(str);
		if (*out == 0)
		{
			if (*str == '-' || *str == '+')
				++signe;
			if (ft_strchr_how_many(str + signe, '0') == ft_strlen(str + signe))
				return (TRUE);
			else
				return (FAIL);
		}
		else
			return (TRUE);
	}
}

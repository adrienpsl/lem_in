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

//// fonction pour gere les erreur
// tester pk mon atoi deconne
int     get_fufu(t_getter get)
{
	char *str = "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

	int a = ft_atoi(str);
	ask_gnl(0, &get->line);


	return (1);
}

//  get le nb de fourmis

// fonction qui gere premiere vague

// fonction qui gere deuxieme vague

//



// premiere fonction get sur gnl les data
void     lem_read_line()
{
    t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));

	free_str(&get.line);

}

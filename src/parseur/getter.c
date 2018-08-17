/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:54 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:38:24 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int		get_nb_foumis(t_getter get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line, NULL);
	if (str_is_int(get->utils.line, &result) == FAIL)
		return (print_err_retrun_int(ERR_FOURMIS_1, DEBUG->print_err));
	else if (result <= 0)
		return (print_err_retrun_int(ERR_FOURMIS_2, DEBUG->print_err));
	get->data->nb_fourmis = ft_atoi(get->utils.line);
	return (TRUE);
}

/*
**	**** VARIABLES
**	data	> sock toute les data du parseur
**
**	**** RETURN
**
**	**** MAKING
*/

int		lem_getter(t_data data)
{
	t_getter_00	get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data = data;
	(void)"  je set utils  ";
	get.utils.fd = DEBUG->fd_file;
	if (get_nb_foumis(&get) == FALSE)
		return (FALSE);
	if (get_room(get.data, &get.utils) == FALSE)
		return (FALSE);
	get_tunnel(data, &get.utils);
	return (TRUE);
}

void	check_data(t_data data)
{
	ft_printf("----> nb fourmis : %d\n---- \n", data->nb_fourmis);
	ft_printf("----> les rooms \n");
	ft_printf("----\n");
	ft_printf("----> les tunnels \n");
	dll_func(data->tunnel, print_tunnel_dll);
	ft_printf("---- \n");
}

/*
** 	le parseur va get toute les err et lees stoker au fur et a mesure
** 	si err, le parseur les print et quitte
*/

int		read_and_parse_data(t_lem lem)
{
	t_data	data;
	int		ret;

	ret = 0;
	data = ft_0_new_memory(sizeof(t_data_00));
	data->room = new_dll();
	data->tunnel = new_dll();
	data->start_room = -1;
	data->end_room = -1;
	ret = lem_getter(data);
	lem->data = data;
	if (DEBUG->parseur == TRUE)
		check_data(data);
	return (ret);
}

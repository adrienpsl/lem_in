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




void init_cache(t_cache cache, t_data data)
{
	cache->all_path = new_dll();
	cache->new_path = new_dll();
	cache->working_path = new_dll();
	cache->close_path = new_dll();
	cache->room = data->room;
	cache->is_full = ft_malloc_protect(sizeof(int) * cache->room->length);
	ft_bzero(cache->is_full, sizeof(int) * cache->room->length);
	cache->name_end = data->end_nb;
}

/*
**    va set la peremiere salle comme path et initialisser les donnees
**    correctement pour lancer l'algo
*/
void set_up()
{
}

// je regarde si dans mes liste j'ai un path qui est arriver a destination
// si oui je le set

int     is_close_path(t_dll_l link, void *name_end_room)
{
    t_path path;
    
    path = link->content;
	if (path->room == 6)
		(void)1;
    if (path->room == *(int*)name_end_room)
        return (TRUE);
    return (FALSE);
}


void drop_closed_path(t_dll working_path, t_dll closed_path, int name_end)
{
	t_dll_l link;
	t_path path;

	link = dll_find_and_drop(working_path, is_close_path, &name_end);
//	printf("%d \n", path->room);

	while (link != NULL)
	{
		path = link->content;
		if (path->room == 6)
			(void)1;
		dll_add(link, closed_path);
		printf("%d \n", path->room);
		link = dll_find_and_drop(working_path, is_close_path, &name_end);
	}
}


void clean_woking(t_cache cache)
{
	destroy_dll_func(&cache->working_path, dll_l_notfree_content);
	drop_closed_path(cache->new_path, cache->close_path, cache->name_end);
	cache->working_path = cache->new_path;
	// scan pour savoir si des chemin meme a l'arriver
	cache->new_path = new_dll();

}
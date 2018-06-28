//
// Created by Adrien PUSEL on 6/28/18.
//

#ifndef LEM_IN_STRUCT_MIN_H
#define LEM_IN_STRUCT_MIN_H

#define PATH 1
#define TAKEN 2

/*
**    tab_room
*/
typedef struct		s_tab_room_00
{
	char taken:1;
	char link:1;
	char path:1;
} 					t_tab_room_00;
typedef t_tab_room_00 *t_tab_room;


typedef struct		s_tunnel_00
{
	char *room_1;
	char *room_2;
} 					t_tunnel_00;
typedef t_tunnel_00 *t_tunnel;

typedef struct		s_room_00
{
	int x;
	int y;
	char *name;
} 					t_room_00;
typedef t_room_00 *t_room;

#endif //LEM_IN_STRUCT_MIN_H

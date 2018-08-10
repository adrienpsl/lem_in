//
// Created by Adrien PUSEL on 6/28/18.
//

#ifndef LEM_IN_STRUCT_MIN_H
#define LEM_IN_STRUCT_MIN_H

#define PATH 1
#define TAKEN 2

typedef struct		s_tunnel_00
{
	char *c_room_1;
	char *c_room_2;
	int room_1;
	int room_2;
} 					t_tunnel_00;
typedef t_tunnel_00 *t_tunnel;

typedef struct		s_room_00
{
	int x;
	int y;
	int nb;
	int type;
	char *name;
} 					t_room_00;
typedef t_room_00 *t_room;

typedef struct		s_path_00
{
	int 	room;
	int		size;
	int		is_full;
	char 	*name_room;
	struct s_path_00 *prev;
} 					t_path_00;
typedef t_path_00 *t_path;

typedef struct s_map_00
{
	char *start;
	size_t size;
	size_t col;
	size_t line;
} t_map_00;

typedef t_map_00 *t_map;


#endif //LEM_IN_STRUCT_MIN_H

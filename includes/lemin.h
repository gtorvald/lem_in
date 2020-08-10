/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:04:06 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:42:31 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct s_link
{
	char			*room1;
	char			*room2;
	struct s_link	*next;
}					t_link;

typedef struct		s_start
{
	char			*name;
	int				x;
	int				y;
}					t_start;

typedef struct		s_end
{
	char			*name;
	int				x;
	int				y;
}					t_end;


typedef struct		s_head
{
	t_room			*first_room;
	t_link			*first_link;
}					t_head;

typedef struct		s_aunt
{
		int			c;
}					t_aunt;

typedef struct		s_lemin
{
	t_room			*room;
	int				count_rooms;
	t_link			*link;
	t_start			*start;
	t_end			*end;
	t_head			*head;
	t_aunt			*aunt;
	bool			**table;
	bool			*statuses;
	bool			*copy;
	int				fd;
}					t_lemin;

typedef struct		s_paths
{
	int				*path;
	int				len;
	int				ants;
	struct s_paths	*next;
}					t_paths;

void			free_lemin(t_lemin **info);
t_lemin			*init_lem();
t_room			*init_room();
t_link			*init_link();
t_start			*init_start();
t_end			*init_end();
t_head			*init_head();
t_aunt			*init_aunt();
void			parser(t_lemin *lem);
bool			parse_aunt(t_lemin *lem);
bool			parse_rooms(t_lemin *lem);
bool			parse_links(t_lemin *lem);
// bool			check_start_end(t_lemin *lem);
void			open_file();
void			print_in_file(char c, char *str, int value);
void			print_all_lists(t_lemin *lem);
bool			handle_err(char *str);
int				num_chr(char *line, char c);
bool			validation(t_lemin *lem);
bool			check_rooms(t_lemin *lem);
bool			check_doubles(t_lemin *lem);
bool			write_link(t_lemin *lem, char *line);
bool			link_first_type(t_lemin *lem, char *line);
bool			link_second_type(t_lemin *lem, char *line);
bool			write_start_room(t_lemin *lem);
bool			write_end_room(t_lemin *lem);
bool			write_room(t_lemin *lem, char *line);
bool			check_dublicate(t_lemin *lem, char *line, char **split);
void			add_start_end(t_lemin *lem);


#endif
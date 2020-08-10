// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:28:10 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:48:53 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			parser(t_lemin *lem)
{
	t_room	*room;

	if (!parse_aunt(lem))
		handle_err("end of parse aunt");
	if (!parse_rooms(lem))
		handle_err("end of parse rooms");
	if (!(parse_links(lem)))
		handle_err("end of parse links");
	add_start_end(lem);
	lem->room = lem->head->first_room;
	lem->link = lem->head->first_link;
}

bool			parse_aunt(t_lemin *lem)
{
	char	*line;

	if (get_next_line(lem->fd, &line) == 1)
	{
		lem->aunt->c = ft_atoi(line);
	}
	if (lem->aunt->c <= 0 || lem->aunt->c > 2147483647)
		handle_err("invalid aunt");	
	return (true);
}

bool			parse_rooms(t_lemin *lem)
{
	char		*line;
	char		**split;
	
	while (get_next_line(lem->fd, &line))
	{
		print_in_file(0, "into cycle: ", -1);
		print_in_file(0, line, -1);
		print_in_file(0, "\n", -1);
		if (line[0] == '#' && line[1] != '#')
			{
				print_in_file(0, "skip: ", -1);
				print_in_file(0, line, -1);
				print_in_file(0, "\n", -1);
				continue ;
			}
		if (ft_strequ(line, "##start") == 1)
			{
				print_in_file(0, "go to start room wia ", -1);
				print_in_file(0, line, -1);
				print_in_file(0, "\n", -1);
				write_start_room(lem);
				continue ;
			}
		if (ft_strcmp(line, "##end") == 0)
			{
				write_end_room(lem);
				print_in_file(0, "end room written\n", -1);
				continue ;
			}
		if (ft_strchr(line, ' ') == NULL)
		{
			print_in_file(0, "go to links", -1);
			print_in_file(0, line, -1);
			if (!(lem->link = (t_link *)malloc(sizeof(t_link))))
				handle_err("cant create new lst for link");
			write_link(lem, line);
			// lem->link->next = NULL;
			print_in_file(0, "check2", -1);
			return (true);
		}
		split = ft_strsplit(line, ' ');
		if (split[1][0] >= '0' && split[1][0] <= '9')
		{
			write_room(lem, line);
		}
		else
			handle_err("invalid room");
	}
	return (true);
}

bool			parse_links(t_lemin *lem)
{
	char		*line;

	while (get_next_line(lem->fd, &line) == 1)
	{
		lem->link->next = (t_link *)malloc(sizeof(t_link));
		lem->link = lem->link->next;
		print_in_file(0, "check", -1);
		write_link(lem, line);
		// lem->link = lem->link->next;
	}
	return (true);
}

void			add_start_end(t_lemin *lem)
{
	lem->room = lem->head->first_room;
	lem->link = lem->head->first_link;
	while (lem->room->next != NULL)
		{
			lem->room = lem->room->next;
		}
	if (!(lem->start->name))
		handle_err("no start room");
	lem->room->name = lem->start->name;
	lem->room->x = lem->start->x;
	lem->room->y = lem->start->y;
	lem->room->next = NULL;
	if (!(lem->end->name))
		handle_err("no end room");
	lem->room->next = (t_room *)malloc(sizeof(t_room));
	lem->room = lem->room->next;
	lem->room->name = lem->end->name;
	lem->room->x = lem->end->x;
	lem->room->y = lem->end->y;
	lem->room->next = NULL;
}

// bool			check_start_end(t_lemin *lem)
// {
// 	if (!(lem->start->name))
// 		handle_err("no start room");
// 	if (!(lem->end->name))
// 		handle_err("no end room");
// 	return (true);
// }
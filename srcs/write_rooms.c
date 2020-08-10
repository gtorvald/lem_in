/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:13:37 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 03:43:30 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			write_start_room(t_lemin *lem)
{
	char		**split;
	char		*line;
	
	if (!(get_next_line(lem->fd, &line)))
		handle_err("invalid read start room");
	if (!line)
		handle_err("invalid read start room 2");
	split = ft_strsplit(line, ' ');
	if (!check_dublicate(lem, line, split))
		handle_err("found duplicate of start room");
	if (!(lem->start->name = ft_strdup(split[0])))
		handle_err("cant write name of start room");
	lem->start->x = ft_atoi(split[1]);
		// handle_err("cant write x of start room");
	lem->start->y = ft_atoi(split[2]);
		// handle_err("cant write y of start room");
	print_in_file(0, "start room is: ", -1);
	print_in_file(0, lem->start->name, -1);
	print_in_file(0, "\n", -1);
	return (true);
}

bool			write_end_room(t_lemin *lem)
{
	char		**split;
	char		*line;
	
	if (!(get_next_line(lem->fd, &line)))
		handle_err("invalid read end room");
	if (!line)
		handle_err("invalid read end room 2");
	split = ft_strsplit(line, ' ');
	if (!check_dublicate(lem, line, split))
		handle_err("found duplicate of end room");
	if (!(lem->end->name = ft_strdup(split[0])))
		handle_err("cant write name of end room");
	lem->end->x = ft_atoi(split[1]);
		// handle_err("cant write x of end room");
	lem->end->y = ft_atoi(split[2]);
		// handle_err("cant write y of end room");
	return (true);
}

bool			write_room(t_lemin *lem, char *line)
{
	char		**split;

	if (line)
		split = ft_strsplit(line, ' ');
	if (lem->head->first_room == NULL)
		lem->head->first_room = lem->room;
	if (!check_dublicate(lem, line, split))
		handle_err("found duplicate");
	if (!(lem->room->name = ft_strdup(split[0])))
		handle_err("cant write name");
	lem->room->x = ft_atoi(split[1]);
		// handle_err("cant write x");
	lem->room->y = ft_atoi(split[2]);
		// handle_err("cant write y");
	if (!(lem->room->next = (t_room *)malloc(sizeof(t_room))))
		handle_err("cant create next lst for room");
	if (!(lem->room = lem->room->next))
		handle_err("cant go to the next lst for room");
		lem->room->next = NULL;
	if (lem->room->next != NULL)
		handle_err("cant NULL lem->room->next");
	return (true);
}

bool			check_dublicate(t_lemin *lem, char *line, char **split)
{
	if (line)
		split = ft_strsplit(line, ' ');
	if (lem->room == lem->head->first_room)
		return (true);
	while (lem->room->next != NULL)
	{
		if (ft_strequ(split[0], lem->room->name))
			handle_err("duplicate: doubles!");
		if ((ft_atoi(split[1]) == lem->room->x) && split[1] >= 0 && ft_atoi(split[1]) > 2147483647)
			handle_err("duplicate: wrong x");
		if ((ft_atoi(split[2]) == lem->room->y) && split[2] < 0 && ft_atoi(split[2]) > 2147483647)
			handle_err("duplicate: wrong y");
		lem->room = lem->room->next;
	}
	print_in_file(0, "end of doubles\n", -1);
	return (true);
}
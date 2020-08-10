/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:45:34 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 14:15:00 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

bool			validation(t_lemin *lem)
{
	if (!(check_rooms(lem)))
		handle_err("validation: cant check room");
	if (!(check_doubles(lem)))
		handle_err("validation: cant check doubles");
	return (true);
}

bool			check_rooms(t_lemin *lem)
{
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	lem->room = lem->head->first_room;
	while (lem->room)
	{
		if (ft_strequ(lem->link->room1, lem->room->name))
			i++;
		if (ft_strequ(lem->link->room2, lem->room->name))
			j++;
		if (i == 1 && j == 1)
			break ;
		lem->room = lem->room->next;
	}
	if (i == 0)
	{
		if (ft_strequ(lem->link->room1, lem->start->name) || ft_strequ(lem->link->room1, lem->end->name))
			i++;
	}
	if (j == 0)
		if (ft_strequ(lem->link->room2, lem->start->name) || ft_strequ(lem->link->room2, lem->end->name))
			j++;
		print_in_file(0, "\ni = ", i);
	print_in_file(0, "\n", -1);
	print_in_file(0, "j = ", j);
	if (i != 1 || j != 1)
		handle_err("check rooms: wrong room");
	if (ft_strequ(lem->link->room1, lem->link->room2))
		handle_err("check rooms: same room in the link");
	return (true);
}

bool			check_doubles(t_lemin *lem)
{
	int			i;
	char		*r1;
	char		*r2;
	t_link		*help;
	
	i = 0;
	r1 = ft_strdup(lem->link->room1);
	r2 = ft_strdup(lem->link->room2);
	lem->link = lem->head->first_link;
	while (lem->link->next)
	{
		if (ft_strequ(lem->link->room1, r1) && ft_strequ(lem->link->room2, r2))
			i++;
		lem->link = lem->link->next;
	}
	print_in_file(0, "double i = ", i);
	if (i > 0)
		handle_err("check doubles: invalid room 1");
	help = lem->head->first_link;
	i = 0;
	while (help)
	{
		if (ft_strequ(help->room1, r2) && ft_strequ(help->room2, r1))
		{
			print_in_file(0, "\n", -1);
			print_in_file(0, help->room1, -1);
			print_in_file(0, " - ", -1);
			print_in_file(0, help->room2, -1);
			print_in_file(0, "\n\n\n", -1);
			print_in_file(0, r1, -1);
			print_in_file(0, " - ", -1);
			print_in_file(0, r2, -1);
			print_in_file(0, "\n", -1);
			i++;
		}
		help = help->next;
	}
	print_in_file(0, "\ni in val link: ", i);
	print_in_file(0, "\n", -1);
	if (i > 0)
		handle_err("check doubles: invalid room 2");
	return (true);
}
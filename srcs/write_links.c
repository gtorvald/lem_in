/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:58:11 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 12:30:12 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			write_link(t_lemin *lem, char *line)
{
	if (lem->head->first_link == NULL)
		lem->head->first_link = lem->link;
	print_in_file(0, "sdelal element!", -1);
	if (num_chr(line, '-') < 1)
		handle_err("write link: no -");
	if (num_chr(line, '-') == 1)
		link_first_type(lem, line);
	if (num_chr(line, '-') > 1)
		link_second_type(lem, line);
	if (!validation(lem))
		handle_err("write link: validation error");
	return (true);
}

bool			link_first_type(t_lemin *lem, char *line)
{
	char		**split;
	int			i;
	int			j;

	if (!line)
		handle_err("links first type: no line");
	split = ft_strsplit(line, '-');
	i = 0;
	j = 0;
	lem->room = lem->head->first_room;
	print_in_file(0, "\n", -1);
	print_in_file(0, line, -1);
	while (lem->room->next != NULL)
	{
		if (ft_strequ(split[0], lem->room->name))
			{
				i++;
			}
		if (ft_strequ(split[1], lem->room->name))
			{
				j++;
			}
		if (i == 1 && j == 1)
			break ;
		lem->room = lem->room->next;
	}
	print_in_file(0, "\ni = ", i);
	print_in_file(0, "\n", -1);
	print_in_file(0, "j = ", j);
	if (i == 0)
	{
		if (ft_strequ(split[0], lem->start->name) || ft_strequ(split[0], lem->end->name))
			i++;
	}
	if (j == 0)
		if (ft_strequ(split[1], lem->start->name) || ft_strequ(split[1], lem->end->name))
			j++;
	if (i == 1 && j == 1)
	{
		lem->link->room1 = ft_strdup(split[0]);
		lem->link->room2 = ft_strdup(split[1]);
	}
	else if (i > 1 || j > 1)
		handle_err("links first type: doubles!");
	else
		handle_err("links first type: no rooms");
	return (true);
}

bool			link_second_type(t_lemin *lem, char *line)
{
	int			i;
	
	i = 0;
	lem->room = lem->head->first_room;
	while (lem->room->next != NULL)
	{
		if (ft_strstr(line, lem->room->name) == 0)
		{
			lem->link->room1 = lem->room->name;
			
		}
		if (ft_strstr(line, lem->room->name) > 0)
			lem->link->room2 = lem->room->name;
		lem->room = lem->room->next;
	}
	return (true);
}
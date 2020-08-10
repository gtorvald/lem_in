/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:45:19 by anastasiase       #+#    #+#             */
/*   Updated: 2020/08/10 17:23:14 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int fd;

void		open_file()
{
	remove("debug.txt");
	fd = open("debug.txt", O_CREAT);
	system("chmod 777 debug.txt");
	fd = open("debug.txt", O_WRONLY);
}

void		print_in_file(char c, char *str, int value)
{
	if (c)
	{
		ft_putchar_fd(c, fd);
		// ft_putchar_fd('\n', fd);
	}
	if (str)
	{
		ft_putstr_fd(str, fd);
		// ft_putchar_fd('\n', fd);
	}
	if (value != -1)
	{
		ft_putnbr_fd(value, fd);
		// ft_putchar_fd('\n', fd);
	}
}

void			print_all_lists(t_lemin *lem)
{
	print_in_file(0, "\n\n\n\n", -1);
	lem->room = lem->head->first_room;
	lem->link = lem->head->first_link;
	print_in_file(0, "aunts: ", lem->aunt->c);
	print_in_file(0, "\n", -1);
	print_in_file(0, "rooms: \n", -1);
	while (lem->room)
	{
		print_in_file(0, lem->room->name, -1);
		print_in_file(0, " ", lem->room->x);
		print_in_file(0, " ", lem->room->y);
		print_in_file(0, "\n", -1);
		lem->room = lem->room->next;
	}
	if (lem->start->name)
	{
		print_in_file(0, "start room: \n", -1);
		print_in_file(0, lem->start->name, -1);
		print_in_file(0, " ", lem->start->x);
		print_in_file(0, " ", lem->start->y);
		print_in_file(0, "\n", -1);
	}
	if (lem->end->name)
	{
		print_in_file(0, "end room: \n", -1);
		print_in_file(0, lem->end->name, -1);
		print_in_file(0, " ", lem->end->x);
		print_in_file(0, " ", lem->end->y);
		print_in_file(0, "\n", -1);
	}
	print_in_file(0, "links: \n", -1);
	while (lem->link)
	{
		print_in_file(0, lem->link->room1, -1);
		print_in_file(0, " - ", -1);
		print_in_file(0, lem->link->room2, -1);
		print_in_file(0, "\n", -1);
		lem->link = lem->link->next;
	}
}
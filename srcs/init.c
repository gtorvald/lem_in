/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:34:18 by phuntik           #+#    #+#             */
/*   Updated: 2020/07/22 18:25:44 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemin			*init_lem()
{
	t_lemin		*lem;
	
	if (!(lem = (t_lemin *)ft_memalloc(sizeof(t_lemin))))
		exit(EXIT_FAILURE);
	lem->room = init_room();
	lem->link = init_link();
	lem->head = init_head();
	lem->end = init_end();
	lem->start = init_start();
	lem->aunt = init_aunt();
	return (lem);
}

t_room			*init_room()
{
	t_room		*room;

	if(!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	room->name = NULL;
	room->next = NULL;
	room->x = 0;
	room->y = 0;
	return(room);
}

t_link			*init_link()
{
	t_link		*link;
	
	// if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
	// 	exit(EXIT_FAILURE);
	// link->room1 = NULL;
	// link->room2 = NULL;
	// link->next = NULL;
	return (link);
}

t_start			*init_start()
{
	t_start		*start;
	
	if (!(start = (t_start *)ft_memalloc(sizeof(t_start))))
		exit(EXIT_FAILURE);
	start->name = NULL;
	start->x = 0;
	start->y = 0;
	return (start);
}

t_end			*init_end()
{
	t_end		*end;

	if (!(end = (t_end *)ft_memalloc(sizeof(t_end))))
		exit(EXIT_FAILURE);
	end->name = NULL;
	end->x = 0;
	end->y = 0;
	return (end);
}

t_head			*init_head()
{
	t_head		*head;
	
	if (!(head = (t_head *)ft_memalloc(sizeof(t_head))))
		exit(EXIT_FAILURE);
	head->first_link = NULL;
	head->first_room = NULL;
	return (head);
}

t_aunt			*init_aunt()
{
	t_aunt		*aunt;

	if (!(aunt = (t_aunt *)ft_memalloc(sizeof(t_aunt))))
		exit(EXIT_FAILURE);
	aunt->c = 0;
	return (aunt);
}
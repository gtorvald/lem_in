#include "../includes/lemin.h"

void	free_room(t_room **rooms)
{
	t_room *help;
	t_room *head;

	head = *rooms;
	help = (*rooms)->next;
	while (help)
	{
		free(head->name);
		free(head);
		head = help;
		help = help->next;
	}
	free(head->name);
	free(head);
}

void	free_links(t_link **link)
{
	t_link *head;
	t_link *help;

	head = *link;
	help = (*link)->next;
	while (help)
	{
		free(head->room1);
		free(head->room2);
		free(head);
		head = help;
		help = help->next;
	}
	free(head->room1);
	free(head->room2);
	free(head);
}

void	free_table(bool **table, int count_rooms)
{
	int i;

	i = 0;
	while (i < count_rooms)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_lemin(t_lemin **info)
{
	free_room(&((*info)->room));
	free_links(&((*info)->link));
	free((*info)->start);
	free((*info)->end);
	free((*info)->head);
	free((*info)->aunt);
	free_table((*info)->table, (*info)->count_rooms);
	free((*info)->statuses);
	free(*info);
}
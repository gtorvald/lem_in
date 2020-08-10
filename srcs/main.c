/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:36:30 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:58:05 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*name_room(t_lemin *info, int index)
{
	int		i;
	t_room	*ptr_room;

	ptr_room = info->room;
	i = 0;
	while (i++ < index)
		ptr_room = ptr_room->next;
	return (ptr_room->name);
}

int		num_room(t_lemin *info, char *name)
{
	int		i;
	t_room	*ptr_room;

	i = 0;
	ptr_room = info->room;
	while (ft_strcmp(ptr_room->name, name))
	{
		ptr_room = ptr_room->next;
		i++;
	}
	return (i);
}

bool	**get_table_of_links(t_lemin *info)
{
	bool	**table;
	t_link	*links;
	int		i;
	int		j;

	table = malloc(info->count_rooms * sizeof(bool*));
	i = 0;
	while (i < info->count_rooms)
		table[i++] = malloc(info->count_rooms * sizeof(bool));
	i = 0;
	while (i < info->count_rooms)
	{
		j = 0;
		while (j < info->count_rooms)
			table[i][j++] = 0;
		i++;
	}
	links = info->link;
	while (links)
	{
		table[num_room(info, links->room1)][num_room(info, links->room2)] = 1;
		table[num_room(info, links->room2)][num_room(info, links->room1)] = 1;
		links = links->next;
	}
	return (table);
}

void	zeroing_bool(bool **stats, int count_rooms)
{
	int		i;

	i = 0;
	while (i < count_rooms)
		(*stats)[i++] = 0;
}

void	swap_and_zeroing(bool **this_lvl, bool **next_lvl, int count_rooms)
{
	bool 	*help;

	help = *this_lvl;
	*this_lvl = *next_lvl;
	*next_lvl = help;
	zeroing_bool(next_lvl, count_rooms);
}

t_paths	*get_path(t_lemin *info, int **prev_room)
{
	int start;
	int len;
	int i;
	int j;
	t_paths *path;

	start = num_room(info, info->start->name);
	len = 1;
	i = num_room(info, info->end->name);
	while (i != start)
	{
		len++;
		i = (*prev_room)[i];
	}
	path = malloc(sizeof(t_paths));
	path->len = len;
	path->ants = 0;
	path->path = malloc(sizeof(int) * len);
	i = len - 2;
	j = num_room(info, info->end->name);
	path->path[len - 1] = j;
	while (i >= 0)
	{
		path->path[i--] = (*prev_room)[j];
		j = (*prev_room)[j];
	}
	free (*prev_room);
	return (path);
}

bool	check_this(bool *this_lvl, int count_rooms)
{
	int i;

	i = 0;
	while (i < count_rooms)
		if (this_lvl[i++])
			return (1);
	return (0);
}

void	initialization(bool **this_lvl, bool **next_lvl, int **prev_room,
t_lemin *info)
{
	int i;

	(*this_lvl) = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(this_lvl, info->count_rooms);
	(*next_lvl) = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(next_lvl, info->count_rooms);
	(*prev_room) = malloc(sizeof(int) * info->count_rooms);
	i = 0;
	while (i < info->count_rooms)
		(*prev_room)[i++] = -1;
	(*this_lvl)[num_room(info, info->start->name)] = 1;
}

bool	searching_path(bool *this_lvl, bool *next_lvl, int **prev_room,
t_lemin *info)
{
	int 	i;
	int 	j;
	bool	flag;

	flag = 0;
	while(!flag && check_this(this_lvl, info->count_rooms))
	{
		i = 0;
		while (!flag && i++ < info->count_rooms)
			if (this_lvl[i - 1])
			{
				j = 0;
				while (!flag && j++ < info->count_rooms)
					if (!info->copy[j -1 ] && info->table[i - 1][j - 1])
					{
						(*prev_room)[j - 1] = i - 1;
						info->copy[j - 1] = 1;
						if (j - 1 == num_room(info, info->end->name))
							flag = 1;
						next_lvl[j - 1] = 1;
					}
			}
		swap_and_zeroing(&this_lvl, &next_lvl, info->count_rooms);
	}
	return (flag);
}

int		*get_array_prev_rooms(t_lemin *info)
{
	bool	*this_lvl;
	bool	*next_lvl;
	int		*prev_room;
	bool	flag;

	initialization(&this_lvl, &next_lvl, &prev_room, info);
	info->copy[num_room(info, info->start->name)] = 1;
	flag = searching_path(this_lvl, next_lvl, &prev_room, info);
	free(this_lvl);
	free(next_lvl); 
	if (!flag)
	{
		free(prev_room);
		return (NULL);
	}
	return (prev_room);
}

t_paths	*search_paths(t_lemin *info)
{
	int		*prev_room;
	int		i;

	info->copy = malloc(sizeof(bool) * info->count_rooms);
	i = 0;
	while (i < info->count_rooms)
	{
		info->copy[i] = info->statuses[i];
		i++;
	}
	if ((prev_room = get_array_prev_rooms(info)) == NULL)
	{
		free(info->copy);
		return (NULL);
	}
	free(info->copy);
	return (get_path(info, &prev_room));
}

void	update_status(t_paths *path, t_lemin *info)
{
	int i;
	int	num_end;

	num_end = num_room(info, info->end->name);
	i = 0;
	while (i < path->len)
	{
		if (path->path[i] != num_end)
			info->statuses[path->path[i]] = 1;
		i++;
	}
}

int		get_count_rooms(t_lemin *info)
{
	t_room	*room;
	int		count;

	room = info->room;
	count = 0;
	while(room)
	{
		count++;
		room = room->next;
	}
	return (count);
}

t_lemin	*build_info(int argc, char **argv)
{
	t_lemin		*info;
	
	info = init_lem();
	if (argc > 1)
		info->fd = open(argv[1], O_RDONLY);
	else
		info->fd = 0;
	open_file();
	parser(info);
	info->count_rooms = get_count_rooms(info);
	return (info);
}

void	distribution_of_ants(t_lemin *info, t_paths *paths)
{
	t_paths *ptr;

	ptr = paths;
	while (info->aunt->c)
	{
		if (ptr->next == NULL)
		{
			ptr->ants++;
			ptr = paths;
		}
		else
		{
			if (ptr->len + ptr->ants <= ptr->next->len + ptr->next->ants)
				ptr->ants++;
			else
				ptr->next->ants++;
			ptr = ptr->next;
		}
		info->aunt->c--;
	}
}

int				main(int argc, char **argv)
{
	t_lemin		*info;
	t_paths *paths = NULL;
	t_paths *head_paths;
	
	info = build_info(argc, argv);
	info->table = get_table_of_links(info);
	info->statuses = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(&info->statuses, info->count_rooms);
	if ((paths = search_paths(info)) == NULL)
	{
		write(2, "ERROR\n", 6);
		free_lemin(&info);
		return (1);
	}
	head_paths = paths;
	update_status(paths, info);
	while ((paths->next = search_paths(info)) != NULL)
	{
		update_status(paths->next, info);
		paths = paths->next;
	}
	distribution_of_ants(info, head_paths);
	// вывод
	paths = head_paths;
	while (paths)
	{
		for (int i = 0; i < paths->len; i++)
			printf("%s ", name_room(info, paths->path[i]));
		printf("- %d\n", paths->ants);
		paths = paths->next;
	}
	free_lemin(&info);
	return (0);
}
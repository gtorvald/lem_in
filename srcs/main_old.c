/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:03:29 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 01:47:24 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main(int argc, char **argv)
{
	t_lemin		*lem;
	
	lem = init_lem();
	if (argc > 1)
		lem->fd = open(argv[1], O_RDONLY);
	else
		lem->fd = 0;
	open_file();
	parser(lem);
	print_all_lists(lem);
}
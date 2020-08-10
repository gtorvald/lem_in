/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:03:27 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 00:07:56 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			handle_err(char *str)
{
	write(0, "ERROR ", 6);
	ft_putstr(str);
	write(0, "\n", 1);
	exit(EXIT_FAILURE);
}

int				num_chr(char *line, char c)
{
	int			i;
	int			n;
	
	i = 0;
	n = 0;
	while(line[i] != '\0')
	{
		if (line[i] == c)
			n++;
		i++;
	}
	return (n);
}
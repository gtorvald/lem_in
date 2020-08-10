/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:13:48 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/25 13:47:30 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, int lenght, void (*f) (int))
{
	int i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		i++;
	}
}
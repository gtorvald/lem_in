/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:36:34 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 18:57:29 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int c)
{
	if (c == -1)
		return (0);
	else
		return (-1);
}

static int	space(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	nb;
	int			nnb;
	int			ct;

	i = 0;
	nb = 0;
	nnb = 1;
	ct = 0;
	while (space(&str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		nnb = ',' - str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + (str[i++] - '0');
		if (nb < 0 || ++ct > 19)
			return (check(nnb));
	}
	return ((int)nb * nnb);
}

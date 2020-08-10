/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:28:46 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 18:59:18 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char		*ft_itoa(int n)
{
	int		len;
	int		n_temp;
	char	*res;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	n_temp = n;
	while (++len && n_temp)
		n_temp /= 10;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	res[--len] = '\0';
	*res = '0';
	n_temp = n;
	while (n_temp)
	{
		res[--len] = ((n_temp % 10) * (ft_check(n))) + '0';
		n_temp /= 10;
	}
	if (n < 0)
		*res = '-';
	return (res);
}

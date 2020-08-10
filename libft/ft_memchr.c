/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:27:58 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/17 11:42:38 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*arr1;
	char	c1;
	int		i;

	arr1 = (char*)arr;
	c1 = (char)c;
	i = 0;
	while (n--)
	{
		if (arr1[i] == c1)
			return (arr1 + i);
		i++;
	}
	return (NULL);
}

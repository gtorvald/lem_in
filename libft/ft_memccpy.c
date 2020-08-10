/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:48:16 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 19:11:41 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char *dest1;
	unsigned char *source1;

	dest1 = (unsigned char *)(dest);
	source1 = (unsigned char *)(source);
	while (n > 0)
	{
		n--;
		*dest1 = *source1;
		dest1++;
		if (*source1 == (unsigned char)c)
			return (dest1);
		source1++;
	}
	return (NULL);
}

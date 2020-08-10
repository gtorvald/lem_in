/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:48:55 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/17 13:34:32 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char *dest1;
	unsigned char *source1;

	dest1 = (unsigned char *)dest;
	source1 = (unsigned char *)source;
	while (n > 0)
	{
		n--;
		*dest1 = *source1;
		dest1++;
		source1++;
	}
	return (dest);
}

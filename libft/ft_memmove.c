/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:36:27 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 12:55:26 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tdst;
	unsigned char *tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (tsrc < tdst)
	{
		while (len--)
			*(unsigned char *)(tdst + len) = *(unsigned char *)(tsrc + len);
	}
	else
		ft_memcpy(tdst, tsrc, len);
	dst = (void *)tdst;
	return (dst);
}

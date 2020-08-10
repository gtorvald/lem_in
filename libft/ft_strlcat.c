/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:57:19 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 12:55:26 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t dst_len;

	dst_len = 0;
	i = ft_strlen(dst);
	if (n > 0)
	{
		while (i + dst_len < n - 1 && src[dst_len])
		{
			dst[i + dst_len] = src[dst_len];
			dst_len++;
		}
	}
	dst[i + dst_len] = '\0';
	if (n < i + dst_len)
		return (n + ft_strlen(src));
	return (i + ft_strlen(src));
}

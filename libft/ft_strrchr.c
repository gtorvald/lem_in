/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:05:24 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/19 14:09:59 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	if (ft_strchr(str, ch) == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	while (str[i] != ch)
		i--;
	return ((char *)str + i);
}

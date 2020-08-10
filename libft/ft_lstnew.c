/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:37:30 by fmelda            #+#    #+#             */
/*   Updated: 2020/03/10 20:32:50 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *input, size_t content_size)
{
	t_list *temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	if (input == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = (void *)malloc(content_size);
		if (!temp->content)
		{
			free(temp);
			return (NULL);
		}
		temp->content_size = content_size;
		ft_memcpy(temp->content, input, content_size);
	}
	temp->next = NULL;
	return (temp);
}

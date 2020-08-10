/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:05:57 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 19:04:35 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!temp)
		return (NULL);
	ret = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
			return (NULL);
		else
			temp = temp->next;
	}
	return (ret);
}

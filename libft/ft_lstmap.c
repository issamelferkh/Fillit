/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:39:44 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/27 07:40:25 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cur;
	t_list	*temp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(cur = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	head = cur;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(cur->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		cur = cur->next;
		lst = lst->next;
	}
	return (head);
}

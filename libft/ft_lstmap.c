/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:01:42 by odursun           #+#    #+#             */
/*   Updated: 2022/01/13 11:17:15 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p_new;
	t_list	*p_old;

	if (!lst)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	p_new = new;
	p_old = lst->next;
	while (p_old)
	{
		p_new->next = ft_lstnew((*f)(p_old->content));
		if (!p_new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		p_new = p_new->next;
		p_old = p_old->next;
	}
	return (new);
}

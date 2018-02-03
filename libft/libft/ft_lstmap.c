/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:47:07 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 16:28:19 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_link;

	if (lst && f)
	{
		new_link = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (new_link)
			new_link->next = ft_lstmap(lst->next, f);
		return (new_link);
	}
	return (NULL);
}

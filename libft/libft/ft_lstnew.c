/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:10:16 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/08 17:21:02 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_link;

	new_link = malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	if (!content)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content = malloc(content_size);
		if (new_link->content)
		{
			ft_memcpy(new_link->content, content, content_size);
			new_link->content_size = content_size;
		}
		else
			return (NULL);
	}
	new_link->next = NULL;
	return (new_link);
}

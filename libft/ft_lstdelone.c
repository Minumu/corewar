/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:50:09 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:50:11 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	if (alst)
	{
		if ((*alst)->content)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			free((void *)*alst);
			*alst = 0;
		}
	}
}

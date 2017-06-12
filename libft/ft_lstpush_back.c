/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:43:40 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:43:44 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_back(t_list **list, void *content, size_t content_size)
{
	t_list *curr_fiel;

	if (*list != NULL)
	{
		curr_fiel = *list;
		while (curr_fiel->next != NULL)
			curr_fiel = curr_fiel->next;
		curr_fiel->next = ft_lstnew_c(content, content_size);
		return (curr_fiel->next);
	}
	else
		*list = ft_lstnew_c(content, content_size);
	return (*list);
}

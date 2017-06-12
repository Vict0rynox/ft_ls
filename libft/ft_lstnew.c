/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:54:08 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:36 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list) * 1);
	if (list != NULL)
	{
		if (content != NULL)
		{
			list->content = malloc(content_size);
			if (list->content != NULL)
				list->content = ft_memcpy(list->content, content, content_size);
			else
				return (NULL);
		}
		else
		{
			list->content = NULL;
			content_size = 0;
		}
		list->content_size = content_size;
		list->next = NULL;
	}
	else
		list = NULL;
	return (list);
}

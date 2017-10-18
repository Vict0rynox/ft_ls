/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:32:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	**lptr;

	new_list = NULL;
	if (lst != NULL)
	{
		lptr = &new_list;
		while (lst != NULL)
		{
			*lptr = f(lst);
			lst = lst->next;
			if(*lptr != NULL)
				lptr = &((*lptr)->next);
		}
	}
	return (new_list);
}

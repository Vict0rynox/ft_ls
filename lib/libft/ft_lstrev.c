/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*new_lst;
	t_list	*lst_next;

	new_lst = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		lst_next = lst->next;
		ft_lstadd(&new_lst, lst);
		lst = lst_next;
	}
	return (new_lst);
}

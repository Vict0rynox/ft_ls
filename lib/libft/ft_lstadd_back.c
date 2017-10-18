/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:43:40 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:43:44 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **list, t_list *lst)
{
	t_list *curr_fiel;

	if (*list != NULL)
	{
		curr_fiel = *list;
		while (curr_fiel->next != NULL)
			curr_fiel = curr_fiel->next;
		curr_fiel->next = lst;
		return (curr_fiel->next);
	}
	else
		*list = lst;
	return (*list);
}

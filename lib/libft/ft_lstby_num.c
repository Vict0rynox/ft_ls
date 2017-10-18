/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstby_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:44:36 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:44:36 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @param num - lst element index
** @return t_list*|NULL - if element not found
*/

t_list	*ft_lstby_num(t_list *lst_head, unsigned int num)
{
	unsigned int i;

	i = 0;
	while (i < num)
	{
		if (lst_head == NULL)
			break ;
		lst_head = lst_head->next;
		i++;
	}
	return (lst_head);
}

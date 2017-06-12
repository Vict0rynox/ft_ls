/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:45:13 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:45:14 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst_head)
{
	size_t size;

	size = 0;
	while (lst_head != NULL)
	{
		size++;
		lst_head = lst_head->next;
	}
	return (size);
}

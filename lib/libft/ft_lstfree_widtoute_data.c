/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_widtoute_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstfree_widtoute_data(t_list **lst)
{
	t_list *lst_ptr;
	t_list *tmp;

	lst_ptr = *lst;
	while (lst_ptr != NULL)
	{
		tmp = lst_ptr;
		lst_ptr = lst_ptr->next;
		free(tmp);
	}
	*lst = NULL;
}

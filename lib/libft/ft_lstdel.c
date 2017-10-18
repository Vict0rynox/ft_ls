/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:24:04 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:17 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lptr;

	if (alst != NULL)
	{
		while ((*alst) != NULL)
		{
			lptr = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = lptr;
		}
		*alst = NULL;
	}
}

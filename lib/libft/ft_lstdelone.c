/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:22:30 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:21 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		if ((*alst)->content != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst)->content = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}

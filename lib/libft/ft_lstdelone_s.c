/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:22:30 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:21 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_s(t_list **alst, void (*del)(void *))
{
	if (alst != NULL && *alst != NULL)
	{
		if ((*alst)->content != NULL)
			del(&(*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}

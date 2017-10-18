/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:15:13 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:14 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*lpst;

	if (alst != NULL)
	{
		lpst = *alst;
		*alst = new;
		(*alst)->next = lpst;
	}
}

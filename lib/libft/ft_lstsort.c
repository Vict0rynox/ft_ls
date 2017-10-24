/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstsort_step(int (*sort_func)(void *, void *),
		t_list **prew, t_list **curr, t_list **start)
{
	t_list	*next;

	if (sort_func == NULL || prew == NULL || curr == NULL || start == NULL)
		return ;
	if (sort_func((*curr)->content, (*curr)->next->content) < 0)
	{
		next = (*curr)->next;
		(*curr)->next = next->next;
		next->next = (*curr);
		if (*prew == NULL)
			(*start) = next;
		else
			(*prew)->next = next;
		*prew = next;
	}
	else
	{
		(*prew) = (*curr);
		(*curr) = (*curr)->next;
	}
}

void	ft_lstsort(t_list **list, int sort_func(void *, void *))
{
	t_list	*curr;
	t_list	*prew;
	size_t	list_size;
	size_t		i;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return ;
	i = 0;
	list_size = ft_lstsize(*list) * ft_lstsize(*list);
	while (i < list_size)
	{
		curr = *list;
		prew = NULL;
		while (curr != NULL && curr->next != NULL)
		{
			ft_lstsort_step(sort_func, &prew, &curr, list);
			i++;
		}
	}
}

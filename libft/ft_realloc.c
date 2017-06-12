/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:42:43 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:42:48 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void	*new;
	size_t	i;
	size_t	size;

	if (new_size == 0)
	{
		free(old);
		return (NULL);
	}
	size = old_size > new_size ? new_size : old_size;
	new = malloc(new_size);
	if (old == NULL)
		return (new);
	i = 0;
	while (i < size)
	{
		((unsigned char *)new)[i] = ((unsigned char *)old)[i];
		i++;
	}
	free(old);
	old = NULL;
	return (new);
}

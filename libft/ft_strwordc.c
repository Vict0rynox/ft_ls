/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:31:55 by vvasilie          #+#    #+#             */
/*   Updated: 2016/12/05 13:31:53 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwordc(const char *s, char c)
{
	size_t	words;
	char	*tmp;

	tmp = (char *)s;
	words = 0;
	while (tmp != NULL && *tmp)
	{
		if (*tmp != c)
			words++;
		tmp = ft_strchr(tmp, c);
		if (tmp != NULL && *tmp)
			tmp++;
	}
	return (words);
}

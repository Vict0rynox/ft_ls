/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_word_ctr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:42:12 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:42:14 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_word_ctr(char const *s, char c)
{
	size_t	w_ctr;

	w_ctr = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			w_ctr++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (w_ctr);
}

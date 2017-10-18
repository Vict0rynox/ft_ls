/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:27 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:35 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new_str;

	new_str = NULL;
	if (s != NULL)
	{
		i = 0;
		len = ft_strlen((char *)s);
		new_str = ft_strnew(len);
		if (new_str != NULL)
		{
			while (i < len)
			{
				new_str[i] = f((unsigned int)i, s[i]);
				i++;
			}
		}
	}
	return (new_str);
}

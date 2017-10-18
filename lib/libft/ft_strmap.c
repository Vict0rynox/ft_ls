/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:32 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*prt_s;
	char	*prt_new_str;
	char	*new_str;

	new_str = NULL;
	if (s != NULL)
	{
		prt_s = (char *)s;
		new_str = ft_strnew(ft_strlen(prt_s));
		if (new_str != NULL)
		{
			prt_new_str = new_str;
			while (*prt_s)
			{
				*prt_new_str = f(*prt_s);
				prt_new_str++;
				prt_s++;
			}
		}
	}
	return (new_str);
}

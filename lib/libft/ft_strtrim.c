/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:49:12 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	char	*ptr_s;
	size_t	len;

	new_str = NULL;
	if (s != NULL)
	{
		ptr_s = (char *)s;
		while (*ptr_s && (*ptr_s == ' ' || *ptr_s == '\n' || *ptr_s == '\t'))
			ptr_s++;
		len = ft_strlen(ptr_s) != 0 ? ft_strlen(ptr_s) : 0;
		while (len != 0 && ptr_s[len - 1] != '\0' &&
			(ptr_s[len - 1] == ' ' || ptr_s[len - 1] == '\n' ||
			ptr_s[len - 1] == '\t'))
			len--;
		new_str = ft_strnew(len);
		if (new_str != NULL && len != 0)
			new_str = ft_strncpy(new_str, ptr_s, len);
	}
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:10 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (new_str != NULL)
	{
		new_str = ft_strcpy(new_str, str);
		new_str[ft_strlen(str)] = '\0';
	}
	else
		new_str = NULL;
	return (new_str);
}

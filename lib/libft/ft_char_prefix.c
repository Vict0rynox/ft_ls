/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_char_prefix(char *str, size_t len, char c)
{
	char	*pref;
	char	*new_str;
	size_t	count;

	count = len - ft_strlen(str);
	pref = ft_strnew(count);
	ft_memset(pref, c, count);
	new_str = ft_strjoin(pref, str);
	free(pref);
	free(str);
	return (new_str);
}

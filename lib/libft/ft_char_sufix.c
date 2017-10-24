/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_sufix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:31 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_char_sufix(char *str, size_t len, char c)
{
	char	*sufix;
	char	*new_str;
	size_t	count;

	count = len - ft_strlen(str);
	sufix = ft_strnew(count);
	ft_memset(sufix, c, count);
	new_str = ft_strjoin(str, sufix);
	free(sufix);
	free(str);
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:49:00 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit_save(char **argc, char const *s, char c)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)s;
	while (tmp != NULL && *tmp)
	{
		if (*tmp != c)
		{
			argc[i] = ft_strnew(ft_strlenchr(tmp, c));
			if (argc[i] == NULL)
				return (NULL);
			argc[i] = ft_strncpy(argc[i], tmp, ft_strlenchr(tmp, c));
			i++;
		}
		tmp = ft_strchr(tmp, c);
		if (tmp != NULL && *tmp)
			tmp++;
	}
	return (argc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**argc;
	size_t	words;

	argc = NULL;
	if (s != NULL)
	{
		words = ft_strwordc(s, c);
		argc = (char **)malloc(sizeof(char *) * (words + 1));
		if (argc != NULL)
		{
			argc[words] = 0;
			argc = ft_strsplit_save(argc, s, c);
		}
	}
	return (argc);
}

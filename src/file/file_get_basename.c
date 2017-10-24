/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_basename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

char	*file_get_basename(char *pathname)
{
	char	*name;
	char	*ptr_last_slash;

	pathname = ft_strdup(pathname);
	if (pathname[ft_strlen(pathname) - 1] == '/')
		pathname[ft_strlen(pathname) - 1] = '\0';
	ptr_last_slash = pathname;
	while (ft_strstr(ptr_last_slash, "/") != NULL)
		ptr_last_slash = ft_strstr(ptr_last_slash, "/") + 1;
	if (ptr_last_slash == pathname)
		return (pathname);
	name = ft_strnew(ft_strlen(ptr_last_slash));
	ft_strcpy(name, ptr_last_slash);
	free(pathname);
	return (name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

char	*file_get_path(char *pathname)
{
	char	*path;
	size_t	size;

	pathname = ft_strdup(pathname);
	if (pathname[ft_strlen(pathname) - 1] == '/')
		pathname[ft_strlen(pathname) - 1] = '\0';
	path = pathname;
	while (ft_strstr(path, "/") != NULL)
		path = ft_strstr(path, "/") + 1;
	if (path == pathname)
		return (ft_strdup(path));
	size = path - pathname - 1;
	path = ft_strnew(size);
	path = ft_strncpy(path, pathname, size);
	free(pathname);
	return (path);
}

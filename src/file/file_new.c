/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

t_file	*file_new(char *pathname)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->path_name = pathname;
	file->name = ft_strdup(file_get_basename(pathname));
	file->path = ft_strdup(file_get_path(pathname));
	return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <sys/stat.h>
#include <pwd.h>

char	*file_get_owner(t_file *file)
{
	struct passwd	*info;
	char			*owner;

	info = getpwuid(file->stat->st_uid);
	owner = ft_strdup(info->pw_name);
	return (owner);
}

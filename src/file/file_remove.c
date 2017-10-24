/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

void	file_remove(t_file **file)
{
	t_file	*f;

	f = *file;
	free(f->path_name);
	free(f->name);
	free(f->path);
	free(f->stat);
	free(f);
	*file = NULL;
}

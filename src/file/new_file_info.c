/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

t_file_info	*new_file_info(t_file *file)
{
	t_file_info	*file_info;

	file_info = malloc(sizeof(t_file_info));
	file_info->type = file_get_type(file);
	file_info->acr = file_get_acr(file);
	file_info->lcount = file_get_lcount(file);
	file_info->owner = file_get_owner(file);
	file_info->group = file_get_group(file);
	file_info->size = file_get_size(file);
	file_info->mimedate = file_get_mimedate(file);
	file_info->filename = file_get_filename(file);
	return (file_info);
}

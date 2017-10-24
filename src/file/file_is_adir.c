/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_adir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

t_bool	file_is_adir(char *pathname)
{
	t_bool	result;

	if (pathname == NULL)
		return (D_FALSE);
	if (file_is_dir(pathname))
		return (D_TRUE);
	pathname = file_get_target_name(pathname);
	if (file_is_dir(pathname))
		result = D_TRUE;
	else
		result = D_FALSE;
	if (pathname != NULL)
		free(pathname);
	return (result);
}

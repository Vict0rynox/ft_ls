/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info_size_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

t_file_info_size	file_info_size_init(void)
{
	t_file_info_size	size;

	size.lcount = 0;
	size.owner = 0;
	size.group = 0;
	size.size = 0;
	size.mimedate = 12;
	size.filename = 0;
	size.type = 1;
	size.acr = 10;
	return (size);
}

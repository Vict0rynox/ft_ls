/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <options/options.h>
#include <file.h>
#include <sys/stat.h>

t_list	*behavior(t_args *args, t_list *lst_dirdata)
{
	t_list *lst_add_path;
	t_list *lst_ptr;
	t_file *file;

	lst_add_path = NULL;
	if (args->up_r == 1)
	{
		lst_ptr = lst_dirdata;
		while (lst_ptr != NULL)
		{
			file = (t_file*)lst_ptr->content;
			if (S_ISDIR(file->stat->st_mode)
			&& ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
				ft_lstpush_back(&lst_add_path, ft_strdup(file->path_name),
								sizeof(char *));
			lst_ptr = lst_ptr->next;
		}
	}
	return (lst_add_path);
}

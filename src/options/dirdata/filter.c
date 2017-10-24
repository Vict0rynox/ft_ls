/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <math.h>
#include <file.h>
#include <libft.h>
#include <options/options.h>

static t_list	*hiden_data_filter(t_list *lst_dirdata)
{
	t_file *file;

	if (lst_dirdata != NULL)
	{
		file = (t_file*)lst_dirdata->content;
		if (file->name[0] != '.')
			return (ft_lstnew_c(file, sizeof(t_file)));
	}
	return (NULL);
}

static int		file_time_sort(t_file *file1, t_file *file2)
{
	long result;

	if (file1 == NULL || file2 == NULL)
		return (NAN);
	result = file1->stat->st_mtimespec.tv_sec -
		file2->stat->st_mtimespec.tv_sec;
	return ((int)result);
}

static int		file_alpha_sort(t_file *file1, t_file *file2)
{
	if (file1 == NULL || file2 == NULL)
		return (NAN);
	return (ft_strcmp(file2->path_name, file1->path_name));
}

void			filter(t_args *args, t_list **lst_dirdata)
{
	t_list	*lst_ptr;

	ft_lstsort(lst_dirdata, (int (*)(void *, void *)) file_alpha_sort);
	if (args->a == 0)
	{
		lst_ptr = ft_lstmap(*lst_dirdata, hiden_data_filter);
		ft_lstfree_widtoute_data(lst_dirdata);
		*lst_dirdata = lst_ptr;
	}
	if (args->t == 1)
		ft_lstsort(lst_dirdata, (int (*)(void *, void *)) file_time_sort);
	if (args->r == 1)
		*lst_dirdata = ft_lstrev(*lst_dirdata);
}

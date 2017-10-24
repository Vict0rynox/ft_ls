/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <math.h>
#include <file.h>

int		time_sort(char *pathname1, char *pathname2)
{
	long result;

	if (pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	result = file_get_time(pathname1) - file_get_time(pathname2);
	return ((int)result);
}

int		alpha_sort(char *pathname1, char *pathname2)
{
	if (pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	return (ft_strcmp(pathname2, pathname1));
}

int		type_sort(char *pathname1, char *pathname2)
{
	if (pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	if (file_is_adir(pathname1) && !file_is_adir(pathname2))
		return (-1);
	if (file_is_adir(pathname1) && !file_is_adir(pathname1))
		return (1);
	return (0);
}

void	filter_args(t_args *args, t_list **list)
{
	if (list == NULL || args == NULL || *list == NULL)
		return ;
	ft_lstsort(list, (int (*)(void *, void *)) alpha_sort);
	if (args->t == 1)
		ft_lstsort(list, (int (*)(void *, void *)) time_sort);
	if (args->r == 1)
		*list = ft_lstrev(*list);
	ft_lstsort(list, (int (*)(void *, void *)) type_sort);
}

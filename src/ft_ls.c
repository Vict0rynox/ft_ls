/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <file.h>

static void	print_result(char *result)
{
	write(STDOUT_FILENO, result, ft_strlen(result));
}

void		ft_ls(t_args *args, t_list *lst_path)
{
	t_list *tmp;
	t_list *lst_dirdata;

	while (lst_path != NULL)
	{
		lst_dirdata = read_info(lst_path->content, args);
		if (lst_dirdata == NULL)
			error_message(lst_path->content);
		else
		{
			filter(args, &lst_dirdata);
			tmp = behavior(args, lst_dirdata);
			if (tmp != NULL)
			{
				if (lst_path->next != NULL)
					ft_lstadd_back(&tmp, lst_path->next);
				lst_path->next = tmp;
			}
		}
		print_result(decorated(args, lst_dirdata, lst_path->content));
		lst_path = lst_path->next;
		if (lst_path != NULL && (file_is_adir(lst_path->content)))
			write(STDOUT_FILENO, "\n", 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <file.h>
#include <math.h>

int	main(int argc, char **argv)
{
	t_list	*lst_path;
	t_args	*options;
	int		i;

	lst_path = NULL;
	options = new_args();
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0'
			&& !options->alow_tire && lst_path == NULL)
			options_by_string(options, argv[i]);
		else
			ft_lstpush_back(&lst_path, ft_strdup(argv[i]), sizeof(char*));
		i++;
	}
	if (lst_path == NULL)
		ft_lstpush_back(&lst_path, "./", sizeof(char*));
	if (lst_path->next == NULL)
		options->firt_path = ft_strdup(lst_path->content);
	filter_args(options, &lst_path);
	ft_ls(options, lst_path);
	return (0);
}

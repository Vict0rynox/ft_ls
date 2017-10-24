/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorated.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <options/options.h>

char	*decorated(t_args *args, t_list *lst_dirdata, char *dir)
{
	if (args->l == 1)
		return (decorated_columns(args, lst_dirdata, dir));
	return (decorated_default(args, lst_dirdata, dir));
}

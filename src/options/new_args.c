/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <options/options.h>
#include <stdlib.h>

t_args	*new_args(void)
{
	t_args	*options;

	options = (t_args*)malloc(sizeof(t_args));
	if (options == NULL)
		return (NULL);
	options->l = 0;
	options->up_r = 0;
	options->a = 0;
	options->r = 0;
	options->t = 0;
	options->firt_path = NULL;
	options->alow_tire = 0;
	return (options);
}

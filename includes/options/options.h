/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:39 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:39 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <libft.h>

typedef struct s_agrs	t_args;

struct					s_agrs
{
	char a;
	char r;
	char t;
	char l;
	char up_r;
	char *firt_path;
	char alow_tire;
};

t_args					*new_args();

void					options_by_string(t_args *args, char *str);

t_list					*behavior(t_args *args, t_list *lst_dirdata);

void					filter(t_args *args, t_list **lst_dirdata);

char					*decorated(
	t_args *args, t_list *lst_dirdata, char *dir);

char					*decorated_default(
	t_args *args, t_list *lst_dirdata, const char *dir);

char					*decorated_columns(
	t_args *args, t_list *lst_dirdata, const char *dir);

#endif

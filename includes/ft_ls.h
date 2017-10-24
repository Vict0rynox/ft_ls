/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:39 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:39 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <libft.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ttycom.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# include <options/options.h>

void	ft_ls(t_args *args, t_list *lst_path);

t_list	*read_directory_data(char *dirname, t_list **lst_file);

void	error_message(const char *pathname);

void	illegal_option(const char *options);

t_list	*read_file(char *pathname, t_list **lst_files);

t_list	*read_info(char *pathname, t_args *args);

void	filter_args(t_args *args, t_list **list);

#endif

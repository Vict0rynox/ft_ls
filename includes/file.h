/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:39 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:39 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <stddef.h>
# include <stdlib.h>
# include <libft.h>
# include <sys/stat.h>

typedef struct s_file			t_file;
typedef struct s_file_info		t_file_info;
typedef struct s_file_info_size	t_file_info_size;

struct							s_file
{
	char		*path;
	char		*name;
	char		*path_name;
	struct stat	*stat;
};

struct							s_file_info
{
	char	*type;
	char	*acr;
	char	*lcount;
	char	*owner;
	char	*group;
	char	*size;
	char	*mimedate;
	char	*filename;
};

struct							s_file_info_size
{
	size_t	type;
	size_t	acr;
	size_t	lcount;
	size_t	owner;
	size_t	group;
	size_t	size;
	size_t	mimedate;
	size_t	filename;
};

t_file							*file_new(char *pathname);

void							file_remove(t_file **file);

char							*file_get_type(t_file *file);

char							*file_get_acr(t_file *file);

char							*file_get_owner(t_file *file);

char							*file_get_group(t_file *file);

char							*file_get_mimedate(t_file *file);

char							*file_get_filename(t_file *file);

char							*file_get_lcount(t_file *file);

char							*file_get_size(t_file *file);

char							*file_get_basename(char *pathname);

char							*file_get_path(char *pathname);

char							*file_get_pathname(char *path, char *name);

char							*file_get_target_name(char *pathname);

t_bool							file_is_dir(const char *pathname);

t_bool							file_is_link(const char *pathname);

time_t							file_get_time(char *pathname);

t_bool							file_is_adir(char *pathname);

t_file_info						*new_file_info(t_file *file);

t_file_info_size				file_info_size_init(void);

#endif

#ifndef FILE_H
#define FILE_H
#include <stddef.h>
#include <stdlib.h>
#include <libft.h>

typedef struct s_file t_file;

struct s_file
{
	char *path;
	char *name;
	char *path_name;
	struct stat *stat;
	//...
};

t_file *file_new(char *pathname);

void file_remove(t_file **file);

char *file_get_type(t_file *file);

char *file_get_acr(t_file *file);

char *file_get_owner(t_file *file);

char *file_get_group(t_file *file);

char *file_get_mimedate(t_file *file);

char *file_get_filename(t_file *file);

char *file_get_lcount(t_file *file);

char *file_get_size(t_file *file);

char	*file_get_basename(char *pathname);

char	*file_get_path(char *pathname);

char	*file_get_pathname(char *path, char *name);

char	*file_get_target_name(char *pathname);

t_bool	file_is_dir(const char *pathname);

t_bool	file_is_link(const char *pathname);

t_bool	file_is_adir(char *pathname);

#endif

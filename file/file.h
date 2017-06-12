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

t_file *file_new(char *path, char *name);

void file_remove(t_file **file);

#endif

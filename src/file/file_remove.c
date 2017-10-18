#include <file.h>

void file_remove(t_file **file)
{
	t_file *f;

	f = *file;
	free(f->path_name);
	free(f->name);
	free(f->path);
	free(f->stat);
	free(f);
	*file = NULL;
}
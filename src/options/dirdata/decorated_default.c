#include <options/options.h>
#include <sys/ttycom.h>
#include <file.h>
#include <sys/ioctl.h>

char *decorated_default(t_args *args, t_list *lst_dirdata, const char *dir) {
	char *result;
	t_file *file;

	result = ft_strnew(0);
	if(file_is_dir(dir) && args->R && (args->firt_path != NULL && ft_strcmp(args->firt_path, dir)))
		result = ft_strjoin(result, ft_strjoin(dir, ":\n"));
	while (lst_dirdata != NULL)
	{
		file = (t_file*)lst_dirdata->content;
		result = ft_strjoin(ft_strjoin(result, file->name), "\n");
		lst_dirdata = lst_dirdata->next;
	}
	return result;
}

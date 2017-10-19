#include <options/options.h>
#include <file.h>
#include <sys/stat.h>

t_list *behavior(t_args *args, t_list *lst_dirdata)
{
	t_list *lst_add_path;

	lst_add_path = NULL;
	if (args->R == 1)
	{
		t_list *lst_ptr;
		t_file *file;

		lst_ptr = lst_dirdata;
		while (lst_ptr != NULL)
		{
			file = (t_file*)lst_ptr->content;
			if(S_ISDIR(file->stat->st_mode) && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
				ft_lstpush_back(&lst_add_path, ft_strdup(file->path_name),
								sizeof(char *));
			lst_ptr = lst_ptr->next;
		}
	}
	return (lst_add_path);
}
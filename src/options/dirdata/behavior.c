#include <options/dirdata/behavior.h>

t_list *behavior(t_opt_behavior options, t_list *lst_dirdata)
{
	t_list *lst_add_path;

	lst_add_path = NULL;
	if (options.R == 1)
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
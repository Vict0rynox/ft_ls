#include <ft_ls.h>
#include <file.h>

void print_result(char *result)
{
	write(STDOUT_FILENO, result, ft_strlen(result));
}

void prepare_pathlst(const t_args *args, t_list *lst_path)
{
	t_list *ptr;
	char *path;

	ptr  = lst_path;
	while (ptr != NULL)
	{
		if(args->l == 0 && file_is_link(ptr->content))
		{
			path = file_get_target_name(ptr->content);
			if(file_is_dir(path))
			{
				free(ptr->content);
				ptr->content = path;
			}
		}
		ptr = ptr->next;
	}
}

int ft_ls(t_args *args, t_list *lst_path)
{
	prepare_pathlst(args, lst_path);
	while (lst_path != NULL)
	{
		t_list *tmp;
		t_list *lst_dirdata;
		char *result;

		lst_dirdata = read_info(lst_path->content);
		if (lst_dirdata == NULL)
			error_message(lst_path->content);
		else
		{
			filter(args, &lst_dirdata);
			tmp = behavior(args, lst_dirdata);
			if(tmp!= NULL)
			{
				if (lst_path->next != NULL)
					ft_lstadd_back(&tmp, lst_path->next);
				lst_path->next = tmp;
			}
		}
		result = decorated(args, lst_dirdata, lst_path->content);
		print_result(result);
		lst_path = lst_path->next;
		if(lst_path != NULL && file_is_dir(lst_path->content))
			write(STDOUT_FILENO, "\n", 1);
	}
	return 0;
}
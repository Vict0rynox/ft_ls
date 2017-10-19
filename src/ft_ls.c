#include <ft_ls.h>

void print_result(char *result)
{
	write(STDOUT_FILENO, result, ft_strlen(result));
	write(STDOUT_FILENO, "\n", 1);
}

int ft_ls(t_args *args, t_list *lst_path)
{
	//TODO: error handle.
	while (lst_path != NULL)
	{
		t_list *tmp;
		t_list *lst_dirdata;
		char *result;

		lst_dirdata = read_info(lst_path->content);
		if (lst_dirdata == NULL)
			break ;
		filter(args, &lst_dirdata);
		tmp = behavior(args, lst_dirdata);
		if(tmp!= NULL)
		{
			if (lst_path->next != NULL)
				ft_lstadd_back(&tmp, lst_path->next);
			lst_path->next = tmp;
		}
		result = decorated(args, lst_dirdata, lst_path->content);
		print_result(result);
		lst_path = lst_path->next;
		//todo: free lst;
	}
	return 0;
}
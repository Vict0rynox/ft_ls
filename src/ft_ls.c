#include <ft_ls.h>
#include <options/dirdata/decorated.h>
#include <options/dirdata/behavior.h>
#include <options/dirdata/filter.h>

void print_result(char *result)
{
	write(STDOUT_FILENO, result, ft_strlen(result));
	write(STDOUT_FILENO, "\n", 1);
}

int ft_ls(t_options *options, t_list *lst_path)
{
	//TODO: error handle.
	while (lst_path != NULL)
	{
		t_list *tmp;
		t_list *lst_dirdata;
		char *result;

		lst_dirdata = read_info(lst_path->content);

		filter(options->filter, &lst_dirdata);

		tmp = behavior(options->behavior, lst_dirdata);
		if(tmp!= NULL)
		{
			if (lst_path->next != NULL)
				ft_lstadd_back(&tmp, lst_path->next);
			lst_path->next = tmp;
		}
		result = decorated(options->decor, lst_dirdata, lst_path->content);
		print_result(result);
		lst_path = lst_path->next;
		//todo: free lst;
	}
	return 0;
}
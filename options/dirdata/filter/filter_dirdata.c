#include "filter_dirdata.h"
#include "file.h"

void ft_lstfree_widtoute_data(t_list **lst)
{
	t_list *lst_ptr;
	t_list *tmp;

	lst_ptr = *lst;
	while(lst_ptr != NULL)
	{
		tmp = lst_ptr;
		lst_ptr = lst_ptr->next;
		free(tmp);
	}
	*lst = NULL;
}

t_list *hiden_data_filter(t_list *lst_dirdata)
{
	t_file *file;

	if(lst_dirdata != NULL)
	{
		file = (t_file*)lst_dirdata->content;
		if(file->name[0] != '.')
			return (ft_lstnew_c(file, sizeof(t_file)));
	}
	return NULL;
}

/**
 * lst_dirdata [t_file]
 * @param options
 * @param lst_dirdata
 */
void filter_dirdata(t_opt_filter options, t_list **lst_dirdata)
{
	t_list *lst_ptr;

	if(options.a == 0)
	{
		lst_ptr = ft_lstmap(*lst_dirdata, hiden_data_filter);
		ft_lstfree_widtoute_data(lst_dirdata);
		*lst_dirdata = lst_ptr;
	}
	//TODO: options.t sorting
	//TODO: options.r reverse
}
#include <sys/stat.h>
#include <math.h>
#include <file.h>
#include <options/options.h>

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

t_list *list_reverse(t_list *lst)
{
	t_list *new_lst;
	t_list *lst_next;

	new_lst = NULL;
	if(lst == NULL)
		return NULL;
	while (lst != NULL)
	{
		lst_next = lst->next;
		ft_lstadd(&new_lst, lst);
		lst = lst_next;
	}
	return (new_lst);
}

void ft_lstsort_step(int (*sort_func)(void *, void *),
		t_list **prew, t_list **curr, t_list **start)
{
	t_list *next;

	if(sort_func == NULL || prew == NULL || curr == NULL || start == NULL)
		return ;
	if(sort_func((*curr)->content, (*curr)->next->content) < 0)
	{
		next = (*curr)->next;
		(*curr)->next = next->next;
		next->next = (*curr);
		if(*prew == NULL)
			(*start) = next;
		else
			(*prew)->next = next;
		*prew = next;
	}
	else
	{
		(*prew) = (*curr);
		(*curr) = (*curr)->next;
	}
}

void	ft_lstsort(t_list **list, int sort_func(void *data1, void *data2))
{
	t_list *curr;
	t_list *prew;
	size_t list_size;
	int	i;

	if(list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	i = 0;
	list_size = ft_lstsize(*list) * ft_lstsize(*list);
	while (i < list_size)
	{
		curr = *list;
		prew = NULL;
		while (curr != NULL && curr->next != NULL)
		{
			ft_lstsort_step(sort_func, &prew, &curr, list);
			i++;
		}
	}
}

int		file_time_sort(t_file *file1, t_file *file2)
{
	long result;

	if(file1 == NULL || file2 == NULL)
		return (NAN);
	result = file1->stat->st_mtimespec.tv_sec - file2->stat->st_mtimespec.tv_sec;
	return ((int)result);
}

int		file_alpha_sort(t_file *file1, t_file *file2)
{
	if(file1 == NULL || file2 == NULL)
		return (NAN);
	return (ft_strcmp(file2->path_name, file1->path_name));
}


/**
 * lst_dirdata [t_file]
 * @param args
 * @param lst_dirdata
 */
void filter(t_args *args, t_list **lst_dirdata)
{
	t_list *lst_ptr;

	ft_lstsort(lst_dirdata, (int (*)(void *, void *)) file_alpha_sort);
	if(args->a == 0)
	{
		lst_ptr = ft_lstmap(*lst_dirdata, hiden_data_filter);
		ft_lstfree_widtoute_data(lst_dirdata);
		*lst_dirdata = lst_ptr;
	}
	if(args->t == 1)
		ft_lstsort(lst_dirdata, (int (*)(void *, void *)) file_time_sort);
	if(args->r == 1)
		*lst_dirdata = list_reverse(*lst_dirdata);

}
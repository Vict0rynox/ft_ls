#ifndef FILTER_DIRDATA_H
#define FILTER_DIRDATA_H

#include <libft.h>

typedef struct s_opt_filter t_opt_filter;

struct s_opt_filter
{
	char a;
	char r;
	char t;
};

void filter(t_opt_filter options, t_list **lst_dirdata);


#endif

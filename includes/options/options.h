#ifndef OPTIONS_H
#define OPTIONS_H

#include <libft.h>

typedef struct s_agrs t_args;

struct s_agrs
{
	char a;
	char r;
	char t;
	char l;
	char G;
	char R;
};

t_args *new_args();

void new_options_by_string(t_args **args, char *str);

t_list *behavior(t_args *args, t_list *lst_dirdata);

void filter(t_args *args, t_list **lst_dirdata);

char *decorated(t_args *args, t_list *lst_dirdata, char *dir);

char *decorated_default(t_list *lst_dirdata, const char *dir);

char *decorated_columns(t_list *lst_dirdata, const char *dir);

#endif

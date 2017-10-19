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

struct s_file_info
{
	char *type;
	char *acr;
	char *lcount;
	char *owner;
	char *group;
	char *size;
	char *mimedate;
	char *filename;
};

struct s_file_info_Size
{
	size_t size_type;//1
	size_t size_acr;//9
	size_t size_lcount;
	size_t size_owner;
	size_t size_group;
	size_t size_size;
	size_t size_mimedate;//12
	size_t size_filename;
};

t_args *new_args();

void new_options_by_string(t_args **args, char *str);

t_list *behavior(t_args *args, t_list *lst_dirdata);

void filter(t_args *args, t_list **lst_dirdata);

char *decorated(t_args *args, t_list *lst_dirdata, char *dir);

char *decorated_default(t_args *args, t_list *lst_dirdata, const char *dir);

char *decorated_columns(t_args *args, t_list *lst_dirdata, const char *dir);

#endif

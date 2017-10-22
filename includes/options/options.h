#ifndef OPTIONS_H
#define OPTIONS_H

#include <libft.h>

typedef struct s_agrs t_args;
typedef struct s_file_info t_file_info;
typedef struct s_file_info_size t_file_info_size;

struct s_agrs
{
	char a;
	char r;
	char t;
	char l;
	char G;
	char R;
	char *firt_path;
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

struct s_file_info_size
{
	size_t type;//1
	size_t acr;//9
	size_t lcount;
	size_t owner;
	size_t group;
	size_t size;
	size_t mimedate;//12
	size_t filename;
};

t_args *new_args();

void options_by_string(t_args *args, char *str);

t_list *behavior(t_args *args, t_list *lst_dirdata);

void filter(t_args *args, t_list **lst_dirdata);

char *decorated(t_args *args, t_list *lst_dirdata, char *dir);

char *decorated_default(t_args *args, t_list *lst_dirdata, const char *dir);

char *decorated_columns(t_args *args, t_list *lst_dirdata, const char *dir);

#endif

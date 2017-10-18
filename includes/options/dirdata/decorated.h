#ifndef DECORATED_DIRDATA_H
#define DECORATED_DIRDATA_H

#include <libft.h>
#include <sys/ttycom.h>
#include <sys/ioctl.h>
#include "file.h"

typedef struct s_opt_decor t_opt_decor;

struct s_opt_decor
{
	char l;
	char G;
};

char *decorated(t_opt_decor options, t_list *lst_dirdata, char *dir);

char *decorated_default(t_list *lst_dirdata, const char *dir);
char *decorated_columns(t_list *lst_dirdata, const char *dir);

#endif

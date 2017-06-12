#ifndef BEHAVIOR_DIRDATA_H
#define BEHAVIOR_DIRDATA_H

#include <libft/libft.h>
#include <sys/stat.h>
#include "file.h"

typedef struct s_opt_behavior t_opt_behavior;

struct s_opt_behavior
{
	char R;
};

t_list *behavior_dirdata(t_opt_behavior options, t_list *lst_dirdata);

#endif

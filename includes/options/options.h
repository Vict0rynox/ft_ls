#ifndef OPTIONS_H
#define OPTIONS_H

#include <options/dirdata/behavior.h>
#include <options/dirdata/decorated.h>
#include <options/dirdata/filter.h>

typedef struct s_options t_options;

struct s_options
{
	t_opt_decor		decor;
	t_opt_filter	filter;
	t_opt_behavior	behavior;
};

void options_init(t_options *options, char *str);

t_options *options_new();

#endif

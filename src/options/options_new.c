#include <options/options.h>
#include <stdlib.h>

t_options *options_new()
{
	t_options *options;

	options = (t_options*)malloc(sizeof(t_options));
	if(options != NULL)
	{
		options->decor.l = 0;
		options->decor.G = 0;
		options->behavior.R = 0;
		options->filter.a = 0;
		options->filter.r = 0;
		options->filter.t = 0;
	}
	return (options);
}
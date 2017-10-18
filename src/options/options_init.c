#include <options/options.h>
#include <stdlib.h>
#include <libft.h>


void options_init(t_options *options, char *str)
{
	int i;

	i = 1;
	if (options != NULL && str != NULL && str[0] == '-' && ft_strlen(str) > 1)
	{
		while (str[i] != '\0')
		{
			if(str[i] == 'l')
				options->decor.l = 1;
			else if(str[i] == 'R')
				options->behavior.R = 1;
			else if(str[i] == 'a')
				options->filter.a = 1;
			else if(str[i] == 'r')
				options->filter.r = 1;
			else if(str[i] == 't')
				options->filter.t = 1;
			i++;
		}
	}
}
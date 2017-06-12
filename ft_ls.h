#ifndef FT_LS_H
#define FT_LS_H

#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ttycom.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include "options.h"


int ft_ls(t_options *options, t_list *lst_path);

t_list *read_directory(char *dirname);

void print_lisfile(t_list *lst_file);

void print_lispath(t_list *lst_path);

#endif

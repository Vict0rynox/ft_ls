#ifndef FT_LS_H
#define FT_LS_H

#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ttycom.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <options/options.h>


int ft_ls(t_args *args, t_list *lst_path);

t_list *read_directory_data(char *dirname, t_list **lst_file);

void print_lisfile(t_list *lst_file);

void print_lispath(t_list *lst_path);

void error_message(char *pathname, char *message);

t_list *read_file(char *pathname, t_list **lst_files);

t_list *read_info(char *pathname);

#endif

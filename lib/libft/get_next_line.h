/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:37:25 by vvasilie          #+#    #+#             */
/*   Updated: 2017/04/17 12:55:27 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include "libft.h"

int						get_next_line(const int fd, char **buff);

typedef struct			s_file_lst {
	struct s_file_lst	*next;
	int					fd;
	char				*buff;
}						t_file_lst;

#endif

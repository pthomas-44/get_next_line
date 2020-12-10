/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:37 by pthomas           #+#    #+#             */
/*   Updated: 2020/12/10 12:45:52 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_buffer
{
	char			buf[BUFFER_SIZE + 1];
	int				i;
	int				fd;
	struct s_buffer	*next;
}				t_buffer;

int				get_next_line(int fd, char **line);
char			**get_line(t_buffer *act, char **line);
int				fill_buffer(t_buffer *act);
t_buffer		*get_actual(t_buffer **start, int fd);

size_t			ft_strlen(const char *s);
size_t			linelen(t_buffer *act);
char			*ft_strjoin(char *s1, char *s2);
void			ft_lstdelone(t_buffer **start, t_buffer *act);
t_buffer		*lstadd_front(t_buffer **start, int fd);

#endif

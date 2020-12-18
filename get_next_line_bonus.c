/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:40 by pthomas           #+#    #+#             */
/*   Updated: 2020/12/11 15:56:34 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*get_actual(t_buffer **start, int fd)
{
	t_buffer *tmp;

	tmp = *start;
	while (tmp)
	{
		if ((tmp)->fd == fd)
			return (tmp);
		tmp = (tmp)->next;
	}
	return (lstadd_front(start, fd));
}

int			fill_buffer(t_buffer *act)
{
	int ret;

	ret = 0;
	if ((ret = (read(act->fd, act->buf, BUFFER_SIZE))) == -1)
		return (-1);
	act->buf[ret] = 0;
	act->i = 0;
	return (ret);
}

char		**get_line(t_buffer *act, char **line)
{
	char	*linetmp;
	int		i;

	i = 0;
	if (!((*line) = malloc(sizeof(char) * (linelen(act) + 1))))
		return (0);
	while (act->i <= BUFFER_SIZE && act->buf[act->i] != '\n'
								&& act->buf[act->i])
	{
		(*line)[i] = act->buf[act->i];
		i++;
		(act->i)++;
	}
	(*line)[i] = 0;
	if (act->buf[act->i] == 0 && act->i < BUFFER_SIZE)
		return (line);
	if (act->buf[act->i] != '\n')
	{
		if (fill_buffer(act) == -1)
			return (0);
		if (!(*line = ft_strjoin(*line, *(get_line(act, &linetmp)))))
			return (NULL);
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static t_buffer	*start;
	t_buffer		*act;
	int				tmp;

	tmp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (!((act = get_actual(&start, fd))))
		return (-1);
	if (act->buf[act->i] == 0 && fd == 0)
		if (fill_buffer(act) == -1)
			return (-1);
	if (!((line = get_line(act, line))))
		return (-1);
	if (act->i == BUFFER_SIZE)
		if (fill_buffer(act) == -1)
			return (-1);
	if (act->buf[act->i] == 0)
	{
		ft_lstdelone(&start, act);
		return (0);
	}
	(act->i)++;
	return (1);
}

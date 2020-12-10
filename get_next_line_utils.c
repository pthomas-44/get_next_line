/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:39 by pthomas           #+#    #+#             */
/*   Updated: 2020/12/10 12:53:08 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		linelen(t_buffer *act)
{
	size_t i;

	i = act->i;
	while (act->buf[i] && act->buf[i] != '\n')
		i++;
	return (i - act->i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = 0;
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (!(l = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
		l[i++] = s1[j++];
	j = 0;
	while (s2[j])
		l[i++] = s2[j++];
	l[i] = '\0';
	free(s1);
	free(s2);
	return (l);
}

void		ft_lstdelone(t_buffer **start, t_buffer *act)
{
	t_buffer *tmp;

	tmp = *start;
	if (*start == act)
	{
		*start = act->next;
		free(act);
	}
	else
	{
		while (tmp->next != act)
			tmp = tmp->next;
		tmp->next = act->next;
		free(act);
	}
}

t_buffer	*lstadd_front(t_buffer **start, int fd)
{
	t_buffer	*new;
	int			ret;

	if (!(new = malloc(sizeof(t_buffer))))
		return (0);
	if ((ret = read(fd, new->buf, BUFFER_SIZE)) == -1)
	{
		free(new);
		return (0);
	}
	new->buf[ret] = 0;
	new->i = 0;
	new->fd = fd;
	new->next = *start;
	*start = new;
	return (new);
}

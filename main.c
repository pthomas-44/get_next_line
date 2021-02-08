/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:28:12 by pthomas           #+#    #+#             */
/*   Updated: 2021/02/08 10:30:01 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/* Remove comments to test miltiple fd */

int		main(void)
{
	char	*line;
	int		fd1;
	// int     fd2;
	int		ret1;
	// int     ret2;
	
	line = 0;
	fd1 = 0;
	// fd2 = open("main.c", O_RDONLY);
	ret1 = 1;
	// ret2 = 1;
	while (ret1 > 0 /*&& ret2 > 0*/)
	{
		ret1 = get_next_line(fd1, &line);
		printf("return = %d | line = %s\n", ret1, line);
		free(line);
		// ret2 = get_next_line(fd2, &line);
		// printf("return = %d | line = %s\n", ret2, line);
		// free(line);
	}
	close(fd1);
	// close(fd2);
	return (0);
}

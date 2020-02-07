/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:44:13 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/07 13:26:50 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <limits.h>

int	main(int ac, char **av)
{
	char	*line;
	char	*gline;
	char	*pline;
	int		fd;
	int		gd;
	int 	pd;
	int		ret;
	int		gret;
	int		pret;

//	while (10)
//	{
		if (ac < 2)
			return (0);
		line = NULL;
		pline = NULL;
		gline = NULL;
		fd = open(av[1], O_RDONLY);
		gd = open(av[2], O_RDONLY);
		pd = open(av[3], O_RDONLY);
		printf("OPEN_MAX = %d\n", OPEN_MAX);
		ret = 1;
		pret = 1;
		gret = 1;
		int i = 1;
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			printf("id: %d test[%d]->%s\n", i, ret, line);
			i++;
			if (ret >= 0)
				free(line);
		/*	gret = get_next_line(gd, &gline);
			printf("test1[%d]->%s\n", gret, gline);
			if (ret >= 0)
			free(gline);
			pret = get_next_line(pd, &pline);
			printf("test2[%d]->%s\n", pret, pline);
			if (pret >= 0)
				free(pline);*/
		}
	//}
//system("leaks a.out");
} 
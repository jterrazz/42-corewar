/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:36:26 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 19:03:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

int	main(int argc, char **argv)
{
	int				fd;
	unsigned char	byte;
	int				i;

	(void)argc;
	printf("\n\n\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &byte, 1) > 0)
	{
		printf("%4d", byte);
		i++;
		if (i % 10 == 0)
			printf("\n");
		if (i % 100 == 0)
			printf("%4d\n\n", i / 100);
	}
	printf("\n\n\n");
	return (0);
}

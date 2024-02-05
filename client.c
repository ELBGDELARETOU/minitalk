/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:58:19 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/02/05 18:13:22 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	sender(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		printf("%c", c);
		while (i-- && i >= 0)
		{
			if (c >> i & 1)
			{
				printf("1");
				kill(pid, SIGUSR2);
			}
			else
			{
				printf("0");
				kill(pid, SIGUSR1);
			}
			usleep(100);
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	sender(atoi(argv[1]), argv[2]);
	return (0);
}
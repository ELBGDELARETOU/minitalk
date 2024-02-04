/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademnaouali <ademnaouali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:58:19 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/02/04 17:16:02 by ademnaouali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	sender(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	
	if (argc != 3 || !argv[2])
		return (1);
	sa.sa_sigaction = sender;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	sender(atoi(argv[1]), argv[2]);
	while (1)
		;
	return (0);
}
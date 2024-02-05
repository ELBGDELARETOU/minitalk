/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:35:29 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/05 19:16:52 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	bit_decrypt(int sig, siginfo_t *struct_sa, void *t)
{
	static int		i = 0;
	static char		c = 0;
	static pid_t	pid;

	if (!pid)
		pid = struct_sa->si_pid;
	if (sig == SIGUSR1)
		c = (c << 1) | 0;
	else
		c = (c << 1) | 1;
	i++;
	if (i > 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	printf("PREND LE TON PID... PREND LE !!!! : %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = bit_decrypt;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		usleep(100);
	return (0);
}

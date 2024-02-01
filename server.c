/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademnaouali <ademnaouali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:35:29 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/01 23:27:52 by ademnaouali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void		bit_decrypt(int sig, siginfo_t *bin_str, void *t)
{
	static int	i;
	static int	c;
	static pid_t pid;

	c = 0;
	i = 0;
	pid = 0;
	if (!pid)
        pid = bin_str->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		printf("%c", c);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
    
	printf("TIENS TON PID : %d\n", getpid());
	sa.sa_sigaction =  bit_decrypt;
	sa.sa_flags = SA_SIGINFO;   
	sigaction(SIGUSR1, &bit_decrypt, 0);
	sigaction(SIGUSR2, &bit_decrypt, 0);
	while(1)
	    pause();
	return(0);
}

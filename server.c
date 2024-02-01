/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:35:29 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/01 17:52:24 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	bit_decrypt(char *bin_str)
{
	int	i;
	int	c;

	i = 7;
	while (*bin_str)
	{
		c |= (*bin_str == '1') << i;
		if (i == 0)
		{
			printf("%c", c);
			i = 7;
			c = 0;
		}
		else
			i--;
		bin_str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	int x;
    
    // sigaction(SIGUSR1, &bit_decrypt, NULL);
	printf("PID : %d\n", getpid());    
	while(1)
	    ;
	return(0);
}

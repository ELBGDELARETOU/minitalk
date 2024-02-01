/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:45 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/01 17:51:21 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	bit_crypt(char *str)
{
	int	i;
	int	c;

	i = 7;
	while (*str)
	{
		while (i >= 0)
		{
			printf("%c", ((*str >> i) & 1) + '0');
			i--;
		}
        str++;
        i = 7;
    }
	printf("\n");
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	
	sa.sa_handler = bit_crypt;
	sa.sa_flags = 0;
	kill(argv[1], SIGUSR2);
	sigaction(SIGUSR2, &sa, NULL);
}
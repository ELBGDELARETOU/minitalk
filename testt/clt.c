#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	signale_receiver(int sig)
{
    if (sig == SIGUSR1)
        printf("1");
    else 
        printf("2");

}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t PID;

	sa.sa_handler = signale_receiver;
	sa.sa_flags = 0;
	PID = atoi(argv[1]);
    signale_receiver(argv[1]);
	while (1)
		;
	return (0);
}
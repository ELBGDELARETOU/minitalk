#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signale_sender(char *str)
{
	int			c;
	static int	i;

	i = 0;
	while (*str)
	{
		c = 7;
		while (c >= 0)
		{
			if ((*str >> c) & 1)
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			c--;
            i++;
		}
        str++;
	}
}
int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signale_sender;
	sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

	printf("Prend le le PID prend le PID, PREND LE : %d\n", getpid());
    while (1)
		pause();
	return (0);
}

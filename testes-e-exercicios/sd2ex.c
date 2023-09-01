#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, n;
	if (argc != 2){ /* check for valid number of command-line arguments */
		fprintf(stderr, "Usage: %s processes (%d)\n", argv[0], argc);
		return 1;
	}
	n = atoi(argv[1]);
	printf("%d\n", n);
	for (i = 1; i < n; i++)
		if (childpid = fork())
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}

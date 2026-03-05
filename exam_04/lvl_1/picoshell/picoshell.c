#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int picosehll(char **cmds[])
{
	pid_t pid;
	int pipefd[2];
	int prev_fd = -1;
	int status;
	int exit_code = 0;
	int i = 0;

	while(cmds[i])
	{
		if(cmds[i + 1] && pipe(pipefd))
			return(1);
		
	}
}
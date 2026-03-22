#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{

}
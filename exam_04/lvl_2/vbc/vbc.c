#include "unistd.h"
#include "stdio.h"
#include "unistd.h"
char *s;

int main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	if(check_input(argv[1]))
		return(1);
	s = argv[1];
	int res = ft_sum();
	printf("%d\n", res);
}
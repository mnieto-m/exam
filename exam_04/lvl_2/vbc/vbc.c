#include "unistd.h"
#include "stdio.h"
#include "unistd.h"

char *s;

int ft_sum()
{
	int sum1 = ft_product();
	int sum2;

	while(*s == '+')
	{
		s++;
		sum2 = ft_product();
		sum1 = sum1 + sum2;
	}
	return(sum1);
}
int checker(char *str)
{
	int i = 0;
	int par = 0;
	char last = "\0";

	while(str[i])
	{
		if(str[i] = '(')
			par ++;
		else if(str[i] == ')')
			par --;

	}
}
int main(int argc, char **argv)
{
	int res;

	if(argc != 2)
		return(1);
	if(checker(argv[1]))
		return(1);
	s = argv[1];

	res = ft_sum();
	printf("%d\n", res);
}
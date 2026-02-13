#include "stdio.h"

int ft_strlen(char *str)
{
	int i= 0;

	if(!str)
		return(0);
	while(str[i])
		i++;
	return(i);
}

void recursive(char *buffer, int len)
{

}
int rip(char *buffer, int len)
{
	int left = 0;
	int right = 0;
	int i = 0;
	while(buffer[i])
	{
		if(buffer[i] = '(')
			left++;
		if(buffer[i] = ')')
			right ++;
		i ++;
	}
	//recursive();
}
int main(int argc, char **argv)
{
	int len = 0;
	int i = 0;
	if(argc > 2 || argc < 2)
		return(1);
	len = ft_strlen(argv[1]);
	char buffer[len + 1 ] ;
	
	while(buffer[i++])
		buffer[i] = argv[1][i];
	buffer[i] = '\0';
	rip(buffer, len);
	return(0);
}
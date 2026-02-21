#include <unistd.h>

void ft_puts(char *str)
{
	int i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int is_valid(char *str)
{
	int open = 0;
	int rem = 0;
	int i = 0;
	
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				rem++;
		}
		i++;
	}
	return (rem + open);
}

int rip(char *str, int indx, char *buff, int len, int rem)
{
	if (indx == len)
	{
		buff[len] = '\0';
		if (!rem && !is_valid(buff))
			ft_puts(buff);
		return(1);
	}
	if ((str[indx] == '(' || str[indx] == ')') && rem > 0)
	{
		buff[indx] = ' ';
		rip(str, indx + 1, buff, len, rem - 1);
	}
	buff[indx] = str[indx];
	rip(str, indx + 1, buff, len, rem);
	return(0);
}

int main(int argc, char **argv)
{
	int len;
	int rem;
	char buffer[1024];

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	rem = is_valid(argv[1]);
	rip(argv[1], 0, buffer, len, rem);
	return (0);
}

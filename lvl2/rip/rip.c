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
	int diff = 0;
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
				diff++;
		}
		i++;
	}
	return (diff + open);
}

void rip(char *str, int indx, char *buff, int len, int diff)
{
	if (indx == len)
	{
		buff[len] = '\0';
		if (!diff && !is_valid(buff))
			ft_puts(buff);
		return ;
	}
	if ((str[indx] == '(' || str[indx] == ')') && diff > 0)
	{
		buff[indx] = ' ';
		rip(str, indx + 1, buff, len, diff - 1);
	}
	buff[indx] = str[indx];
	rip(str, indx + 1, buff, len, diff);
}

int main(int argc, char **argv)
{
	int len;
	int diff;
	char buffer[1024];

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	diff = is_valid(argv[1]);
	rip(argv[1], 0, buffer, len, diff);
	return (0);
}

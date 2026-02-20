#include <stdlib.h>
#include <stdio.h>

void print(int *buf, int len)
{
	int i = 0;

	while (i < len)
	{
		printf("%d", buf[i]);
		if (i < len - 1)
			printf(" ");
		else
			printf("\n");
		i++;
	}
}

void solve(int target, int *nums, int size, int i, int *buf, int len, int sum)
{
	if (i == size)
	{
		if (sum == target)
			print(buf, len);
		return ;
	}
	// Incluir nums[i]
	buf[len] = nums[i];
	solve(target, nums, size, i + 1, buf, len + 1, sum + nums[i]);
	// No incluir nums[i]
	solve(target, nums, size, i + 1, buf, len, sum);
}

int main(int argc, char **argv)
{
	if (argc <= 2)
		return (1);

	int size = argc - 2;
	int nums[size];
	int buf[size];
	int i = 0;

	while (i < size)
	{
		nums[i] = atoi(argv[i + 2]);
		i++;
	}
	solve(atoi(argv[1]), nums, size, 0, buf, 0, 0);
	return (0);
}




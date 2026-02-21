#include <stdlib.h>
#include <stdio.h>

void print(int *buf, int j)
{
	int i = 0;

	while (i < j)
	{
		printf("%d", buf[i]);
		if (i < j - 1)
			printf(" ");
		else
			printf("\n");
		i++;
	}
}

void solve(int target, int *nums, int size, int i, int *buf, int j, int sum)
{
	if (i == size)
	{
		if (sum == target)
			print(buf, j);
		return ;
	}
	// Incluir nums[i]
	buf[j] = nums[i];
	solve(target, nums, size, i + 1, buf, j + 1, sum + nums[i]);
	// No incluir nums[i]
	solve(target, nums, size, i + 1, buf, j, sum);
}

int main(int argc, char **argv)
{
	if (argc <= 2)
		return (1);

	int size = argc - 2;
	int nums[size + 1];
	int buf[size + 1];
	int i = 0;

	while (i < size)
	{
		nums[i] = atoi(argv[i + 2]);
		i++;
	}
	solve(atoi(argv[1]), nums, size, 0, buf, 0, 0);
	return (0);
}




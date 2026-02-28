#include <stdlib.h>
#include <stdio.h>

//nOT NEEDED
/*static int	all_digit(int c, char **v)
{
	int	i = 0;
	int	j;

	while (++i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] >= '0' && v[i][j] <= '9')
				++j;
			else
				return (0);
		} 
	}
	return (1);
}*/
	
static void	print(int *r, int i)
{
	int	j = 0;

	while (j < i)
	{
		printf("%d", r[j]);
			++j;
		if (j == i)
			printf("\n"); 
		else
			printf(" ");
	}
}

static int	sum(int t, int *r, int sub_size)
{
	int	sum = 0;
	int	i = 0;

	while (i < sub_size)
		sum += r[i++];
	if (sum == t)
		return (1);
	return (0);
}

//Check every option of subset. Only print if a complete subset == t
//Data: 2 arrays
//	2 sizes. One is always the same. sub_size increase or remains, depends
//		of choice
//	Index from original array
//	t == target number
//	*jump is flag to know if in some place we have written
static void	recur(int t, int *a, int i, int *r, int size, int sub_size)
{
	if (i == size)//This is the base case: reach last number of original set
	{
		if (sum(t, r, sub_size))
			print(r, sub_size);
		return ;//In case of forget this return, SEGMENTATION FAULT (CORE DUMPED)
	}
	r[sub_size] = a[i];//New integer added to set
	recur(t, a, i + 1, r, size, sub_size + 1);
		//Option_1: increase set to add next integers from original
	recur(t, a, i + 1, r, size, sub_size);
		//Option_2: change the new integer with next one. 
		//	This is the backtrack
}

//Conversion from array to integers, then call to recursion.
//In case of no valid results on recursion, print "\n"
static int	prog(int size, char **v)
{
	int	a[size];
	int	r[size];//Two arrays with same size, perhaps r will
			//not store nothing yet
	int	t;
	int	a_index = 0;
	int	r_index = 0;//Index for r array

	t = atoi(v[1]);//Target number
	while (a_index < size)
	{
		a[a_index] = atoi(v[a_index + 2]);//Complete array with all data
		++a_index;
	}
	a_index = 0;
	recur(t, a, a_index, r, size, r_index);//Indexes value is 0
	return (1);
}

//Checks data (not sure if it is needed) and calls program
int	main(int c, char **v)
{
	//Not needed to check if chars are digits
	//Only returns 1 in case of less than 2 args or in case of leaks, if you allocate with malloc
	if (c > 2 && prog(c - 2, v))
		return (0);
	return (1);
}
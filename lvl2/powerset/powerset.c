/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:53:19 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/02/12 20:16:50 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print (int *buffer , int j)
{
	int i  = 0;

	while(i < j)
	{
		printf("%i",buffer[i]);
		++i;
		if(j == i)
			printf("\n");
		else
			printf(" ");
	}
}

int sum(int setter,int *buffer, int j)
{
	int sum = 0;
	int i = 0;
	
	while (i < j)
		sum += buffer[i++];
	if(sum == setter)
		return(1);
	return(0);
}

void recursive(int setter, int *num, int i, int *buffer, int j, int size)
{
	if(i == size)
	{
		if(sum(setter,buffer,j))
			print(buffer, j);
		return;
	}
	buffer[j] = num[i];
	recursive(setter, num, i + 1, buffer,j + 1, size);
	recursive(setter, num, i + 1, buffer,j, size);
}
int powerset(int setter ,int *num, int size)
{
	int buff[size];
	int i = 0;
	int j = 0;
	
	recursive(setter,num, i, buff, j, size);
	return(0);
}
int main(int argc, char **argv)
{
	int num[argc - 2];
	int setter = 0;
	int i= 0;
	
	if (argc <= 2)
		return(1);
	setter = atoi(argv[1]);
	while(argv[(i + 2)])
	{
		num[i] = atoi(argv[i + 2]);
		i++;
	}
	powerset(setter, num ,(argc - 2));
	return(0);
}




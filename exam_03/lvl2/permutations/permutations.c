/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:09:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/02/26 10:34:26 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "unistd.h"
#include "stdio.h"

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str && str[i] != 0)
		i++;
	return(i);
}
void print_str(char *s)
{
	int i = 0;
	
	while (s[i])
	{
		write(1,&s[i],1);
		i++;
	}
	write(1,"\n",1);
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort(char *str, int start)
{
	int i = start ;
	int j = 0;
	
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if(str[j] < str[i])
				swap(&str[j],&str[i]);
			j++;
		}
		i++;
	}
}
void permuted(char *str, int indx, int len )
{	
	int j = indx;
	if(indx == len)
	{
		print_str(str);
		return		;
	}
	while(j <len)
	{
		swap(&str[indx],&str[j]);
		sort(str, indx + 1);
		permuted(str, indx + 1, len);
		sort(str, indx);
		j++;
	}
		
}
int main(int argc, char **argv)
{ 
	int len = 0;
	if(argc != 2 )
	{
		write(1,"\n",1);
		return(1);
	}
	len = ft_strlen(argv[1]);
	sort(argv[1], 0);
	permuted(argv[1], 0 ,len);
	return(0);
}
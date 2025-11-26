/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:11:40 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/11/26 22:34:11 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i] != 0)
		i++;
	return(i);
}

void *ft_filter(char* buffer, char*  index)
{
	int i = 0;//iterador de buffer
	int j = 0;// iterador de index
	int len = ft_strlen(index);
	
	while(buffer[i])
	{
		j = 0;
		while( buffer[i + j] != '\0' && buffer[i + j] == index[j])// iterar para encontrar primera concurrencia
			j++;
		if(j == len)
		{
			while(j-- > 0)
				write(1,"*",1);
			i += len;
		}
		else//imprime si no encuentra la concurrencia
		{
			write(1,&buffer[i],1);
			i++;
		}
	}
}


int main(int argc, char **argv)
{
	int i = 0;
	int bit = 1;
	char buffer[99999];
	if( argc != 2 || argv[1] == NULL ||  ft_strlen(argv[1]) == 0 )
		return(1);
	while(bit > 0)
	{
		bit = read(0, &buffer[i],10);
		if(bit < 0)
		{
			write(2,"Error: ",7);
			perror("");
			return(1);
		}
		i += bit;	
	}
	buffer[i] = '\0';
	ft_filter(buffer, argv[1]);
}
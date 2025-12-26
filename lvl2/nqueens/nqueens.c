/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/12/26 18:14:52 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_posisiones(int nq, int *posisiones)
{
	int i = 0;
	while(i < nq)
	{
		printf("%d", posisiones[i]);
		if(i+ 1 != nq)
			printf(" ");
		i++;
	}
	printf("\n");
}
int is_valid(int *posisiones, int row , int col)
{
	int i = row - 1;
	
	while(i >= 0 && posisiones[i] != -1)
	{
		int temp = posisiones[i];
		if(col == temp || col == temp + (row - i) || col == temp -(row - i))
			return(0);
		i--;
	}
	return(1);
}

void solve(int nq, int  *posisiones, int row)
{
	int col = 0; // posiscion columnas
	while(col < nq)
	{
		if(is_valid(posisiones,row , col))
		{
			posisiones[row] = col;
			if(row + 1 == nq)
				print_posisiones(nq,posisiones);
			else
				solve(nq,posisiones, row + 1);
		}
		posisiones[row] = -1;
		col++;
	}
}

int main(int argc , char **argv)
{
	int nq = 0;// numero de reinas
	int *posiones = 0; //posiscion actual 
	int i = 0;// iterador
	
	if(argc != 2)
		return(1);
	nq = atoi(argv[1]); // guardo la el numero de reinas en la varibles 
	posiones = malloc(nq *sizeof(int)); // me creo un array de int en malloc
	while(i < nq)
		posiones[i++] = -1; // relleno de -1 el array
	solve(nq, posiones, 0);// solucion donde paso el numero de reinas, el array de posisiones y 0 rows
	free(posiones);
}
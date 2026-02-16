/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/02/16 21:42:05 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_posisiones(int nq, int *posisiones)
{
	int i = 0; // declaramos un iterador 
	while(i < nq)  //usaremos un bucle while para imprimir comparando el iterador y el numero de reinas
	{
		printf("%d", posisiones[i]); // imprimiremos cada valor del array de enteros en la posicion del iterador
		if(i+ 1 != nq) //comprobaremos antes de iterar si es que el siguiente valor de i es distinto a nq para imprimir un espacio
			printf(" ");
		i++;
	}
	printf("\n");
}
int is_valid(int *posisiones, int row , int col)
{
	int i = row - 1; // daremos el valor de una columna menor 
	int temp ; // declaramos un variable int temporal para poder retener y comparar despues 
	while(i >= 0 && posisiones[i] != -1) //
	{
		temp = posisiones[i];

		// 1️⃣ Misma columna
		if(col == temp)
			return(0);

		// 2️⃣ Misma diagonal principal
		if(col == temp + (row - i))
			return(0);

		// 3️⃣ Misma diagonal secundaria
		if(col == temp - (row - i))
			return(0);
		i--;
	}
	return(1);
}

void solve(int nq, int  *posisiones, int row)
{
	int col = 0; // declaramos 
	while(col < nq) // bucle comparando columnas y numero de reinas 
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

int main(int argc , char ** argv)
{
	int nq = 0;

	if(argc != 2)
		return(1);
	nq = atoi(argv[1]);

	int posiciones[nq];
	solve(nq, posiciones , 0);
	return (0);
}
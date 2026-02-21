/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/02/21 22:08:44 by mnieto-m         ###   ########.fr       */
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
int is_valid(int *posisiones, int row, int col)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (posisiones[i] == col)
			return (0);
		if (posisiones[i] == col + (row - i))
			return (0);
		if (posisiones[i] == col - (row - i))
			return (0);
		i++;
	}
	return (1);
}

void solve(int nq, int *posisiones, int row, int col)
{
	if (col == nq)
	{
		if (row == nq)
			print_posisiones(nq, posisiones);
		return ;
	}
	if (is_valid(posisiones, row, col))
	{
		posisiones[row] = col;
		solve(nq, posisiones, row + 1, 0);
		posisiones[row] = -1;
	}
	solve(nq, posisiones, row, col + 1);
}

int main(int argc , char ** argv)
{
	int nq = 0;

	if(argc != 2)
		return(1);
	nq = atoi(argv[1]);

	int posiciones[nq];
	solve(nq, posiciones, 0, 0);
	return (0);
}
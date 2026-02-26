/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/02/26 09:19:51 by mnieto-m         ###   ########.fr       */
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
int is_valid(int *posisiones, int col, int row)
{
	int i = 0;
	while(i < col)
	{
		if(row == posisiones[i])
			return(0);
		if(row == posisiones[i] + (col - i))
			return(0);
		if(row == posisiones[i] - (col - i))
			return(0);
		i++;
	}
	return(1);
}

void solve(int nq, int *posisiones, int col)
{
    if (col == nq)
    {
        print(nq, posisiones);
        return;
    }
    int row = 0;
    while (row < nq)
    {
        if (is_valid(posisiones, col, row))
        {
            posisiones[col] = row;
            solve(nq, posisiones, col + 1);
        }
        row++;
    }
}

int main(int argc , char ** argv)
{
	int nq = 0;

	if(argc != 2)
		return(1);
	nq = atoi(argv[1]);
	if(nq == 0)
		return(0);
	int posiciones[nq];
	solve(nq, posiciones, 0);
	return (0);
}
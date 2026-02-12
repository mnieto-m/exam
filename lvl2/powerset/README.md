# exam_03

Este repositorio incluye ejercicios del examen. Este README documenta en detalle el ejercicio de powerset y explica la teoria y el flujo del codigo.

## Problema (powerset con suma objetivo)

Dado un numero objetivo `t` y una lista de enteros, hay que imprimir todos los subconjuntos cuya suma sea exactamente `t`. Cada subconjunto se imprime en una linea con sus elementos separados por espacios.

## Teoria: powerset y backtracking

- **Powerset**: el conjunto de todos los subconjuntos de un conjunto de `n` elementos. Tiene `2^n` subconjuntos, incluyendo el vacio.
- **Backtracking**: tecnica recursiva que explora decisiones binarias en cada paso (incluir o excluir un elemento). Produce un arbol de recursion con `2^n` hojas.
- **Recursion binaria**: en cada indice `i`, se abren dos ramas:
	- **Incluir** el elemento `a[i]` en el subconjunto actual.
	- **Excluir** el elemento `a[i]`.
- **Caso base**: cuando se ha decidido para todos los elementos (`i == size`), se evalua si la suma del subconjunto actual coincide con `t`.

Complejidad:
- **Tiempo**: `O(2^n * n)` en el peor caso, porque en cada hoja se recorre el subconjunto para sumar.
- **Memoria**: `O(n)` por la profundidad maxima de recursion y el arreglo temporal del subconjunto.

## Entrada y salida

Formato esperado por el programa en [lvl2/powerset/powerset_die.c](lvl2/powerset/powerset_die.c):

```
./a.out t x1 x2 x3 ... xn
```

- `t` es la suma objetivo.
- `x1..xn` son los valores del conjunto.

Salida: cada subconjunto valido se imprime en una linea. Si no hay subconjuntos validos, no se imprime nada.

## Detalle del codigo

Este resumen describe lo que ocurre en [lvl2/powerset/powerset_die.c](lvl2/powerset/powerset_die.c).

### 1) `print(int *r, int i)`

Imprime los primeros `i` elementos del arreglo `r`. Es el subconjunto actual construido por la recursion. Se formatea con espacios y salto de linea final.

### 2) `sum(int t, int *r, int sub_size)`

Suma los primeros `sub_size` elementos de `r` y compara el resultado con `t`. Devuelve 1 si coinciden.

### 3) `recur(int t, int *a, int i, int *r, int size, int sub_size)`

Es el corazon del backtracking. Parametros clave:

- `a`: arreglo original con los `size` elementos.
- `i`: indice actual dentro de `a`.
- `r`: arreglo temporal donde se construye el subconjunto.
- `sub_size`: tamano actual del subconjunto (cuantos elementos validos hay en `r`).

Flujo:

1. **Caso base**: si `i == size`, ya se tomo una decision para cada elemento. Si la suma del subconjunto actual es `t`, se imprime.
2. **Rama incluir**: se guarda `a[i]` en `r[sub_size]` y se avanza a `i + 1` con `sub_size + 1`.
3. **Rama excluir**: se avanza a `i + 1` sin aumentar `sub_size` (se descarta `a[i]`).

Esto genera el arbol completo de subconjuntos. La variable `r` se reutiliza en cada rama; el control del tamano actual se hace con `sub_size`, por lo que no se necesitan copias.

### 4) `prog(int size, char **v)`

- Convierte `v[1]` a entero para obtener `t`.
- Convierte el resto de argumentos a enteros y llena `a`.
- Llama a `recur` con `i = 0` y `sub_size = 0` para empezar.

### 5) `main(int c, char **v)`

Comprueba que hay al menos un objetivo y un numero (`c > 2`). Si se cumple, ejecuta `prog`.

## Observaciones

- El programa no valida que los argumentos sean numericos. Asume entrada correcta.
- La suma del subconjunto se calcula al final de cada rama, no durante la recursion. Se podria optimizar calculando la suma incremental, pero no es necesario para el ejercicio.
- El arreglo `r` puede contener basura mas alla de `sub_size`, pero esos valores nunca se leen.

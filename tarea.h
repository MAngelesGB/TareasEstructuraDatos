#include <cstring>
#include <iostream>
#include <cstdint>

#include <random>
#include <fstream>

using namespace std;

struct BitVector {
	/*
	guarda enteros positivos como bits en un array
	0000 0000b = 
	0001 0001b = 1, 5
	1111 0000b = 5,6,7,8

	i_array = indice / sizeof(array[0])*8; //numero de bits en cada elemento del array
	i_byte =  1 << indice % sizeof(array[0])*8
	array[i_array] |= i_byte; // set
	*/


	/*
	pone en 1 el bit seccionado
	*/
	void set(std::size_t n);

	/*
	regresa el valor del bit en la posicion n
	*/
	bool get(std::size_t n);

	/*
	regresa el valor del siguiente bit falso
	ej.
	array[0] = 1110 1111b
	next_false(1) = 5
	*/
	int64_t next_false(std::size_t n);

	/*
	ditto
	*/
	int64_t prev_false(std::size_t n);
};


/*tarea

archivo grande (4.5GB)
400 millones de numeros unicos. no ordenados
regresar un numero unico que NO este dentro de ese archivo grande
limite de los numberos es 430 millones
condicion. esta prohibido ordenar el archivo.
*/
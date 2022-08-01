#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string.h>

using namespace std;

/* Esta funcion imprime el el menu y retorna una opcion escogida por el usuario */
int menu(void);

/* Esta funcion imprime una lista de transacciones */
void print(char **, char **, int *, int );

/* Esta funcion se encarga de añadir al final de un arreglo de enteros un nuevo numero */
int* append(int *, int, int);

/* Esta funcion se encarga de añadir al final de un arreglo una cadena de caracteres */
char** append(char **, int, char *);

#endif // TOOLS_H

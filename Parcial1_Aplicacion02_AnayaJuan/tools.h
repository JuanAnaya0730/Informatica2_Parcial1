#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string.h>

using namespace std;

/* Esta funcion imprime el el menu y retorna una opcion escogida por el usuario */
int menu(void);

/* Esta funcion convierte las letras minusculas de un arreglo en mayusculas */
void to_upper(char *);

/* Esta funcion imprime una lista de usuarios */
void print(long long *, char **, char **, long long *, char **, char **, int);

/* Esta funcion imprime los usuarios que tengan determinado criterio */
void print(long long *, char **, char **, long long *, char **, char **, int, char *);

/* Esta funcion busca un entero en un arreglo y retorna un booleano que indica si fue encontrado */
bool find(long long *, int, long long);

/* Esta funcion se encarga de añadir al final de un arreglo de enteros un nuevo numero */
long long* append(long long *, int, long long);

/* Esta funcion se encarga de añadir al final de un arreglo una cadena de caracteres */
char** append(char **, int, char *);

#endif // TOOLS_H

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string.h>

using namespace std;

/* Esta funcion imprime el el menu y retorna una opcion escogida por el usuario */
int menu(void);

/* Esta funcion convierte las letras minusculas de un arreglo en mayusculas */
void to_upper(char *);

/* Esta funcion imprime un arreglo bidimencional */
void print(char **, int);

/* Esta funcion imprime las categorias que tengan determinado criterio */
void print(char **, int, char *);

/* Esta funcion busca una cadena de caracteres en un arreglo y retorna un booleano
que indica si la encontro */
bool find(char **, int, char *);

/* Esta funcion se encarga de añadir al final de un arreglo una cadena de caracteres */
char** append(char **, int, char *);

#endif // TOOLS_H

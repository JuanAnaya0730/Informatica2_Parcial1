#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string.h>

using namespace std;

int menu(void);
void to_upper(char *);
bool find(char **, int, char *);
void print(char **, int);
char** append(char **, int, char *);

#endif // TOOLS_H

#include "tools.h"

int menu(void){
    int option;
    cout << "Menu:\n"
            "1. Registrar categoria.\n"
            "2. Mostrar categorias.\n"
            "3. Terminar.\n"
            "Opcion: ";
    cin >> option;
    cin.ignore();

    return option;
}

void to_upper(char *array){
    for(int i=0; i<int(strlen(array)); ++i){
        if(array[i] >= 97 && array[i] <= 122){
            array[i] -= 32;
        }
    }
}

bool find(char **array, int size, char *str){
    for(int i=0; i<size; ++i){
        if(strcmp(array[i], str) == 0){
            return true;
        }
    }
    return false;
}

void print(char **array, int size){
    for(int i=0; i<size; ++i){
        cout << i+1 << ". " << array[i] << endl;
    }
    cout << endl;
}

char** append(char **array, int size, char *str){
    char **copyArray = new char*[size+1];
    for(int i=0; i<size; ++i){
        copyArray[i] = array[i];
    }

    delete[] array;

    copyArray[size] = new char[strlen(str)+1];
    for(int i=0; i<int(strlen(str)+1); ++i){
        copyArray[size][i] = str[i];
    }

    return copyArray;
}

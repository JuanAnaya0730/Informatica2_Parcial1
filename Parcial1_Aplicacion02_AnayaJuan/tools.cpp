#include "tools.h"

int menu(void){
    int option; // Variable que almacenara una opcion escogida por el usuario

    /* Se imprime el menu con la opciones correspondientes a la aplicacion */
    cout << "Menu:\n"
            "1. Registrar usuario.\n"
            "2. Mostrar usuarios.\n"
            "3. Terminar.\n"
            "Opcion: ";
    cin >> option; // Se toma la opcion escogida por el usuario
    cin.ignore();

    return option; // Se retorna la opcion escogida por el usuario
}

void print(long long *id, char **name, char **country, long long *phone,
           char **dateBirth, char **category, int size){
    // id, name, country, phone, dateBirth y category son los arreglos a imprimir
    // size es el tamaño de los arreglos a imprimir

    cout << "Usuarios" << endl;

    /* Se imprime cada valor de cada arreglo */
    for(int i=0; i<size; ++i){
        cout << i+1 << ". " << id[i] << " - " << name[i] << " - " << country[i] << " - ";

        if(phone[i] != 0) cout << phone[i] << " - ";
        else cout << "x - ";

        cout << dateBirth[i] << " - " << category[i] << endl;
    }
    cout << endl;
}


bool find(long long *array, int size, long long num){
    for(int i=0; i<size; ++i){
        if(array[i] == num){
            return true;
        }
    }
    return false;
}


long long* append(long long *array, int size, long long num){
    // array es el arreglo al que se le añadira un numero
    // size es el tamaño del arreglo al que se le añadira el numero
    // num es numero que sera añadido

    long long *copyArray = new long long[size+1]; // Este arreglo almacenara una copia del arreglo original

    /* Se copian todos los elementos del arreglo original */
    for(int i=0; i<size; ++i){
        copyArray[i] = array[i];
    }

    delete[] array; // Se libera el espacio en memoria del arreglo original

    copyArray[size] = num; // Se agrega el nuevo numero

    return copyArray; // Se retorna el arreglo con el nuevo numero

}

char** append(char **array, int size, char *str){
    // array es el arreglo al que se le añadira una palabra
    // size es el tamaño del arreglo al que se le añadira la palabra
    // str es la palabra que sera añadida

    char **copyArray = new char*[size+1]; // Este arreglo almacenara una copia del arreglo original

    /* Se copian todos los elementos del arreglo original */
    for(int i=0; i<size; ++i){
        copyArray[i] = array[i];
    }

    delete[] array; // Se libera el espacio en memoria del arreglo original

    copyArray[size] = new char[strlen(str)+1]; // Se asigna memoria para la nueva palabra

    /* Se agrega la nueva palabra */
    for(int i=0; i<int(strlen(str)+1); ++i){
        copyArray[size][i] = str[i];
    }

    return copyArray; // Se retorna el arreglo con la nueva palabra
}

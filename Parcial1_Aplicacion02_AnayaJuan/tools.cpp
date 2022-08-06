#include "tools.h"

int menu(void){
    string option; // Variable que almacenara una opcion escogida por el usuario

    /* Se imprime el menu con la opciones correspondientes a la aplicacion */
    while(true){
        cout << "Menu:\n"
                "1. Registrar usuario.\n"
                "2. Mostrar usuarios.\n"
                "3. Busqueda inteligente.\n"
                "4. Terminar.\n"
                "Opcion: ";
        cin >> option; // Se toma la opcion escogida por el usuario

        system("cls"); // Se limpia la consola

        if(option[0] < 49 || option[0] > 52 || option.length() > 1){
            /* Si la opcion ingresada no es valida se le indica al usuario que intente de nuevo */
            cout << "Opcion invalida. Intente de nuevo.\n" << endl;

        }else{
            break;
        }
    }
    cin.ignore();

    return stoi(option); // Se retorna la opcion escogida por el usuario
}

void to_upper(char *array){
    // array es el arreglo que se pasara a mayusculas

    for(int i=0; i<int(strlen(array)); ++i){
        /* Se verifica si una determinada letra del arreglo el minuscula */
        if(array[i] >= 97 && array[i] <= 122){
            array[i] -= 32; // Se convierte la letra misnuscula en mayuscula
        }
    }
}

void print(long long *id, char **name, char **country, long long *phone,
           char **dateBirth, char **category, int size){
    // id, name, country, phone, dateBirth y category son los arreglos a imprimir
    // size es el tamaño de los arreglos a imprimir

    cout << "Usuarios" << endl;

    /* Se imprime cada valor de cada arreglo */
    for(int i=0; i<size; ++i){
        cout << i+1 << ". " << id[i] << " - " << name[i] << " - " << country[i] << " - ";

        /* Si un usuario no ingreso su telefono se imprime un x en su lugar */
        if(phone[i] != 0) cout << phone[i] << " - ";
        else cout << "X - ";

        cout << dateBirth[i] << " - " << category[i] << endl;
    }
    cout << endl;
}

void print(long long *id, char **name, char **country, long long *phone,
           char **dateBirth, char **category, int size, char *str){
    // id, name, country, phone, dateBirth y category son los arreglos que contienen los posibles usuarios a imprimir
    // size es el tamaño de los arreglos a imprimir
    // str es el criterio de busqueda

    char *aux1 = nullptr, *aux2 = nullptr;

    cout << "Resultados para " << str << endl;

    /* Se itera todo el arreglo */
    for(int i=0, j=1; i<size; ++i){

        /* Se pasa el dato int de id a un arreglo de caracteres para facilitar la busqueda*/
        aux1 = new char[to_string(id[i]).length()+1];
        for(int h=0; h < int(to_string(id[i]).length()) + 1; ++h){
            aux1[h] = to_string(id[i])[h];
        }

        /* Se pasa el dato int de phone a un arreglo de caracteres para facilitar la busqueda*/
        aux2 = new char[to_string(phone[i]).length()+1];
        for(int h=0; h < int(to_string(phone[i]).length()) + 1; ++h){
            aux2[h] = to_string(phone[i])[h];
        }

        /* Se comprueba si cada palabra cumple con el criterio de busqueda,
        si lo cumple dicha paralabra se imprime */
        if(strstr(aux1, str) != nullptr || strstr(name[i], str) != nullptr || strstr(country[i], str) != nullptr ||
           strstr(aux2, str) != nullptr || strstr(dateBirth[i], str) != nullptr || strstr(category[i], str) != nullptr){

            cout << j << ". " << id[i] << " - " << name[i] << " - " << country[i] << " - ";

            /* Si un usuario no ingreso su telefono se imprime un x en su lugar */
            if(phone[i] != 0) cout << phone[i] << " - ";
            else cout << "X - ";

            cout << dateBirth[i] << " - " << category[i] << endl;

            j++;
        }else if(j==1 && i==size-1){
            cout << "Sin resultados" << endl;
        }

        delete[] aux1;
        delete[] aux2;
    }
    cout << endl;
}


bool find(long long *array, int size, long long num){
    // array es es arreglo en el que se hara la busqueda
    // size es el tamaño del arreglo en el que se hara la busqueda
    // num es el numero a buscar

    for(int i=0; i<size; ++i){
        /* Se comprueba si cada valor de array es igual al numero buscado */
        if(array[i] == num){
            return true; // Se retorna true si el numero a buscar existe en el arreglo
        }
    }
    return false; // Se retorna false si e numero albuscar NO existe en el arreglo
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

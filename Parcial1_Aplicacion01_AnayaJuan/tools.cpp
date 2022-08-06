#include "tools.h"

int menu(void){
    string option; // Variable que almacenara una opcion escogida por el usuario

    /* Se imprime el menu con la opciones correspondientes a la aplicacion */
    while(true){
        cout << "Menu:\n"
                "1. Registrar categoria.\n"
                "2. Mostrar categorias.\n"
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

void print(char **array, int size){
    // array es el arreglo a imprimir
    // size es el tamaño del arrglo a imprimir

    cout << "Categorias" << endl;

    /* Se imprime cada palabra del arreglo */
    for(int i=0; i<size; ++i){
        cout << i+1 << ". " << array[i] << endl;
    }
    cout << endl;
}

void print(char **array, int size, char *str){
    // array es el arreglo que contiene las palabras a imprimir
    // size es el tamaño del arreglo que contiene las palabras a imprimir
    // str criterio que tiene que cumplir una palabra para que se pueda imprimir

    cout << "Resultados para " << str << endl;

    /* Se itera todo el arreglo */
    for(int i=0, j=1; i<size; ++i){

        /* Se comprueba si cada palabra cumple con el criterio de busqueda,
        si lo cumple dicha paralabra se imprime */
        if(strstr(array[i], str) != nullptr){
            cout << j << ". " << array[i] << endl;
            j++;
        }else if(j==1 && i==size-1){
            cout << "Sin resultados" << endl;
        }
    }
    cout << endl;
}

bool find(char **array, int size, char *str){
    // array es el arreglo en el cual se realizara la busqueda
    // size es el tamaño del arreglo en el que se realizara la busqueda
    // str es la palabra a buscar

    for(int i=0; i<size; ++i){
        /* Se verifica si cada palabra de array es igual a str */
        if(strcmp(array[i], str) == 0){
            return true; // Se retorna true si se encuuentra la palabra
        }
    }

    return false; // Se retorna false en caso de que no se encuentre la palabra
}

bool find_keyword(char *str1, char *str2){
    if(strstr(str1, str2) != nullptr){
        return true;
    }

    return false;
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

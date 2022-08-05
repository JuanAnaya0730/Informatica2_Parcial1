#include "tools.h"

using namespace std;

int main()
{
    int option; // Esta variable almacenara la opcion que tome el usurario
    int size = 0; // Esta variable almacenara el tamaño de un arreglo de char de dos dimenciones
    char **categories = nullptr; // Este sera el arreglo que ira almacenando las categorias ingresadas
    char *aux = new char[20]; // Este arreglo almacenara temporalmente una categoria ingresada

    while(true)
    {
        option = menu(); // Se imprime el menu de opciones

        if(option == 1){

            /* Se le pide al usuario que ingrese una nueva categoria */
            cout << "Ingrese la nueva categoria: ";
            cin.getline(aux, 20);

            system("cls"); // Se limpia la consola

            /* La categoria ingresada se transforma a mayusculas para que sea mas facil
            ver si ya se encuentra dentro de las categorias registradas */
            to_upper(aux);

            /* Se verifica si la categoria ingresada ya esta registrada, si No esta registrada
            se agrega a la lista de registros, de lo contrario se imprime un mendaje correspondiente */
            if(!find(categories, size, aux))
            {
                categories = append(categories, size, aux);
                cout << "La categoria " << categories[size] << " ha sido registrada con exito.\n" << endl;

                size++; // Se aumenta el tamaño del arreglo ya que se añadio un nuevo dato

            }else {
                cout << "La categoria ingresada ya se encuentra registrada.\n" << endl;
            }

        }else if(option == 2){
            /* Se imprime la lista de las categorias que estan registradas */
            print(categories, size);

        }else if(option == 3){

            /* Se le pide al usuario que ingrese una palabra clave para realizar la busqueda */
            cout << "Ingrese la palabra clave: ";
            cin.getline(aux, 20);

            system("cls"); // Se limpia la consola

            /* El criterio ingresado se convierte a su equivalente en mayuscula */
            to_upper(aux);

            /* Se imprimen todas la categorias que tienen la palabra calve ingresada */
            print(categories, size, aux);

        }else{
            break; // Se rompe el ciclo infinito
        }
    }

    /* Se liberan los espacios de memoria de las columnas */
    for(int i=0; i<size; ++i){
        delete[] categories[i];
    }
    delete[] categories; // Se liberan los espacios de memoria de las filas
    delete[] aux; // Se libera la memoria

    return 0;
}

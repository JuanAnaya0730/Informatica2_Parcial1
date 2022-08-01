#include <iostream>
#include <tools.h>

using namespace std;

int main()
{
    int option; // Esta variable almacenara la opcion que tome el usurario
    int size = 0; // Esta variable almacenara el tamaño de un arreglo de char de dos dimenciones
    char **data = nullptr; // Este sera el arreglo que ira almacenando las categorias ingresadas
    char *category = new char[20]; // Este arreglo almacenara temporalmente una categoria ingresada

    while(true)
    {
        option = menu();
        system("cls");

        if(option == 1){

            /* Se le pide al usuario que ingrese una nueva categoria */
            cout << "Ingrese la nueva categoria: ";
            cin.getline(category, 20);

            system("cls"); // Se limpia la consola

            /* La categoria ingresada se transforma a mayusculas para que sea mas facil
            ver si ya se encuentra dentro de las categorias registradas */
            to_upper(category);

            /* Se verifica si la categoria ingresada ya esta registrada, si No esta registrada
            se agrega a la lista de registros, de lo contrario se imprime un mendaje correspondiente */
            if(!find(data, size, category))
            {
                data = append(data, size, category);
                cout << "La categoria " << category << " ha sido registrada con exito.\n" << endl;
            }
            else cout << "La categoria ingresada ya se encuentra registrada." << endl;

            size++; // Se aumenta el tamaño del arreglo ya que se añadio un nuevo dato;

        }else if(option == 2){
            /* Se imprime la lista de las categorias que estan registradas */
            print(data, size);

        }else if(option == 3){
            break; // Se rompe el ciclo infinito
        }else{
            /* Si la opcion ingresada no es valida se le indica al usuario que intente de nuevo */
            cout << "Opcion invalida. Intente de nuevo.\n" << endl;
        }
    }

    /* Se liberan los espacios de memoria de las columnas */
    for(int i=0; i<size; ++i){
        delete[] data[i];
    }
    delete[] data; // Se liberan los espacios de memoria de las filas
    delete[] category; // Se libera la memoria
    return 0;
}

/*
    while(run){
        cout << "Menu:\n"
                "1. Registrar categoria.\n"
                "2. Mostrar categorias.\n"
                "3. Terminar.\n"
                "Opcion: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case '1':
            cout << "Ingrese la nueva categoria: ";
            cin.getline(category, 20);

            to_upper(category);
            if(find(data, size, category)){
                cout << "La categoria ya esta registrada" << endl;
            }else{
                data = append(data, size, category);
            }

            size++;

            break;
        case '2':
            print(data, size);

            break;
        case '3':
            run = false;

            break;
        default:
            cout << "Opcion no valida." << endl;

            break;
        }
    }

*/

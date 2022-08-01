#include "tools.h"

using namespace std;

int main()
{
    int option; // Esta variable almacenara la opcion que tome el usuario
    int size=0; // Esta variable almacenara el tamaño de los arreglos cuyos datos forman un usuario
    long long *id = nullptr; // Este sera el arreglo que ira almacenando los id de cada usuario
    char **name = nullptr; // Este sera el arreglo que ira almacenando los nombres ingresados
    char **country = nullptr; // Este sera el arreglo que ira almacenando los paises a los que pertenecen los usuarios
    long long *phone = nullptr; // Este sera el arreglo que ira almacenando los telefonos de cada usuario
    char **dateBirth = nullptr; // Este sera el arreglo que ira almacenando las fechas de nacimiento de cada usuario
    char **category = nullptr; // Este sera el arreglo que ira almacenando la categoria a la que pertenecen los usuarios
    char *aux = new char[50]; // Este arreglo servira para recibir los datos ingresados y asignarlos a su correspondiente arreglo
    long long auxNum; // Esta variable servira para almacenar temporalmente datos numericos de un usuario

    while(true)
    {
        option = menu(); // Se imprime el menu de opciones
        system("cls"); // Se limpia la consola

        if(option == 1){
            cout << "Ingrese su Nro. de documento(obligatorio): ";
            cin >> auxNum;
            cin.ignore();

            /* Se verifica si el usuario ingresado ya esta registrada, si No esta registrado
            se le asigna un registro, de lo contrario se imprime un mendaje correspondiente */
            if(!find(id, size, auxNum)){
                id = append(id, size, auxNum);
                system("cls"); // Se limpia la consola

                cout << "Ingrese su nombre y apellido(obligatorio): ";
                cin.getline(aux, 50);
                name = append(name, size, aux);
                system("cls"); // Se limpia la consola

                cout << "Nota: Envie una x si no desea ingresar su pais\n"
                        "Ingrese su pais: ";
                cin.getline(aux, 50);
                country = append(country, size, aux);
                system("cls"); // Se limpia la consola

                cout << "Nota: Envie un 0 si no desea ingresar su telefono. \n"
                        "Ingrese su Nro. de telefono: ";
                cin >> auxNum;
                cin.ignore();
                phone = append(phone, size, auxNum);
                system("cls"); // Se limpia la consola

                cout << "Nota: Envie una x si no desea ingresar la fecha\n"
                        "Ingrese su fecha de nacimiento: ";
                cin.getline(aux, 50);
                dateBirth = append(dateBirth, size, aux);
                system("cls"); // Se limpia la consola

                cout << "Nota: Envie una x si no desea ingresar su categoria\n"
                        "Ingrese su categoria: ";
                cin.getline(aux, 50);
                category = append(category, size, aux);
                system("cls"); // Se limpia la consola

                cout << "El usuario ha sido registrado exitosamente.\n" << endl;

            }else{
                system("cls");
                cout << "El usuario ingresado ya se encuentra registrado.\n" << endl;
            }

            size++; // Se aumenta el tamaño de los arreglos ya que se añadio una nueva transaccion

        }else if(option == 2){
            /* Se imprime la lista de las transacciones que estan registradas */
            print(id, name, country, phone, dateBirth, category, size);

        }else if(option == 3){
            break; // Se rompe el ciclo infinito

        }else{
            /* Si la opcion ingresada no es valida se le indica al usuario que intente de nuevo */
            cout << "Opcion invalida. Intente de nuevo.\n" << endl;
        }
    }

    /* Se liberan los espacios de memoria de las columnas */
    for(int i=0; i<size; ++i){
        delete[] name[i];
        delete[] country[i];
        delete[] dateBirth[i];
        delete[] category[i];
    }
    delete[] name; // Se liberan los espacios de memoria de las filas
    delete[] country; // Se liberan los espacios de memoria de las filas
    delete[] dateBirth; // Se liberan los espacios de memoria de las filas
    delete[] category; // Se liberan los espacios de memoria de las filas
    delete[] id; // Se libera la memoria
    delete[] phone; // Se libera la memoria
    delete[] aux; // Se libera la memoria

    return 0;
}

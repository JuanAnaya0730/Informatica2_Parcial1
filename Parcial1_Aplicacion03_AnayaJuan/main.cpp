#include "tools.h"

using namespace std;

int main()
{
    int option; // Esta variable almacenara la opcion que tome el usuario
    int size=0; // Esta variable almacenara el tamaño de los arreglos cuyos datos forman una transaccion
    char **date = nullptr; // Este sera el arreglo que ira almacenando las fechas ingresadas
    char **time = nullptr; // Este sera el arreglo que ira almacenando las horas ingresadas
    int *money = nullptr; // Este sera el arreglo que ira almacenando los montos hechos en cada tranccion
    char *aux = new char[20]; // Este arreglo servira para recibir los datos ingresados y asignarlos a su correspondiente arreglo

    while(true)
    {
        option = menu(); // Se imprime el menu de opciones
        system("cls"); // Se limpia la consola

        if(option == 1){

            /* Se le pide al usuario  que ingrese la fecha de la transaccion */
            cout << "Ingrese la fecha(DD/MM/AAAA) de la transaccion: ";
            cin.getline(aux, 20);
            date = append(date, size, aux);

            system("cls"); // Se limpia la consola

            /* Se le pide al usuario  que ingrese la hora de la transaccion */
            cout << "Ingrese la hora(HH:MMam/pm) de la transaccion: ";
            cin.getline(aux, 20);
            time = append(time, size, aux);

            system("cls"); // Se limpia la consola

            /* Se le pide al usuario  que ingrese el monto de la transaccion */
            cout << "Ingrese el monto de la transaccion: ";
            cin >> option;
            money = append(money, size, option);

            system("cls"); // Se limpia la consola

            cout << "Transaccion registrada exitosamente.\n" << endl;

            size++; // Se aumenta el tamaño de los arreglos ya que se añadio una nueva transaccion

        }else if(option == 2){
            /* Se imprime la lista de las transacciones que estan registradas */
            print(date, time, money, size);

        }else if(option == 3){
            break; // Se rompe el ciclo infinito

        }else{
            /* Si la opcion ingresada no es valida se le indica al usuario que intente de nuevo */
            cout << "Opcion invalida. Intente de nuevo.\n" << endl;
        }
    }

    /* Se liberan los espacios de memoria de las columnas */
    for(int i=0; i<size; ++i){
        delete[] date[i];
        delete[] time[i];
    }
    delete[] date; // Se liberan los espacios de memoria de las filas
    delete[] time; // Se liberan los espacios de memoria de las filas
    delete[] money; // Se libera la memoria
    delete[] aux; // Se libera la memoria

    return 0;
}

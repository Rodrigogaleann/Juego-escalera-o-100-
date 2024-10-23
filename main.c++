#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
#include "headerUno.h"  // Header para funcion mostrar menu.
#include "calcularReglas.h" // Header para las reglas, también contiene la función dibujar dados.
#include "modoManual.h" // Header para modo manual.
//#include "modoUnJugador.h" // Header para modo un jugador.
#include "mostrarReglamento.h" // Header para mostrar reglamento.

int main()
{
    srand(time(NULL));  // Ejecutar semilla para números aleatorios de los dados(elementos del vector).
    int opcion=1; // Poner la opción en uno.

    while(opcion != 0)
    {
        mostrarMenu(); // función que muestra el menú del juego.
        cin >> opcion;
        switch(opcion)  // Desplegando con un switch cada opción disponible que utilizaremos llamando funciones.
        {
        case 1:
            //modoUnJugador();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            modoManual();
            break;
        case 5:
            mostrarReglamento();
            break;
        case 0:
            cout << "Saliendo del programa..."  << endl;
            break;

        default:
            cout << "Ingresa una opcion correcta " << endl;
            //system ("pause");
            break;
        }
        if (opcion != 0) //// FORMA PARA REEMPLAZAR A SYSTEM ("PAUSE") DE WINDOWS EN LINUX.
        {
            cout << "Presiona Enter para continuar..." << endl;
            cin.ignore();  // Ignorar el carácter de nueva línea restante.
            cin.get();     // Esperar a que el usuario presione Enter.
        }
    }
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
#include "FUNCIONES.h"
#include "calcularReglas.h"
#include "mostrarReglamento.h"
#include "modoDosJugadores.h"
#include "mostrarReglamento.h"

#include "mostrarPuntacionAlta.h"

int main()
{
    srand(time(NULL));
    const int TAM=6;

    int puntuacionAlta = 0;             // PUNTEROS PARA MOSTAR PUNTUACIÓN MAXIMA
    string nombrePuntuacionAlta;        // PUNTEROS PARA MOSTRAR PUNTÚACIÓN MÁXIMA

    int opcion=1;
    int dados[TAM]= {1,2,3,4,5,6};
    while(opcion!=0)
    {
        mostrarMenu();
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            modoUnjugador(dados, TAM, &puntuacionAlta, &nombrePuntuacionAlta);
            cargarVectorAleatorio(dados, TAM);
            mostrarVector(dados, TAM);
            sumarLanzamiento(dados, TAM);
            break;

        case 2:
            modoDosJugadores(&puntuacionAlta, &nombrePuntuacionAlta); // Agregué el modo Dos jugadores con el header que contiene calcular reglas.
            break;

        case 3:
            modoManual(dados, TAM, &puntuacionAlta, &nombrePuntuacionAlta); // función para modo manual.
            break;

        case 4:
            mostrarReglamento(); // Función para mostrar reglamento.
            break;

        case 5:
            mostrarPuntuacionAlta(puntuacionAlta, nombrePuntuacionAlta); // Función para mostrar puntuación alta.
            break;

        case 0:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            //system("pause");
            cin.ignore();  // Ignorar el carácter de nueva línea restante
            cin.get();     // Esperar a que el usuario presione Enter
            break;
        }
    }
    return 0;
}

#ifndef MODOUNJUGADOR_H_INCLUDED
#define MODOUNJUGADOR_H_INCLUDED

#include "headerUno.h"
#include "calcularReglas.h"

void modoUnJugador();

void modoUnJugador()

{
    system("clear"); // Limpiar la consola en linux.
    // system ("cls"); // limpiar la consola en windows.
    const int TAM = 6;
    int dados[TAM] = {1,2,3,4,5,6};
    int lanzamientos = 3; // numero de lanzamientos.
    int puntajeTotal = 0;// acumulador de puntaje.
    int rondas = 0; // contador de rondas.
    string nombre; // string para ingresar nombre.

    cout << "Ingrese el nombre del jugador: " << endl;
    cin.ignore();  // ingreso de nombre.
    getline(cin, nombre); // ingreso de nombre.

    while(puntajeTotal <= 100) // para contar las rondas.
    {
        rondas++; // contador de rondas.
        int maxRonda = 0; // variable que servirá para ubicar la RONDA CON PUNTAJE MÁXIMO.
        for(int lanzamiento = 1; lanzamiento <= lanzamientos; lanzamiento++) // Tenemos 3 lanzamientos por ronda , sale bucle for.
        {
            system ("clear");
            // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.

            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "TURNO DE: " << nombre << " | " << "RONDA N° " << rondas << " | " << "PUNTAJE TOTAL: " << puntajeTotal << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxRonda << endl;
            cout << "LANZAMIENTO NÚMERO: " << lanzamiento << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cargarVectorAleatorio(dados, TAM);
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "EL RESULTADO DE LOS DADOS ES: " << endl;
            mostrarVector(dados,TAM);
              for (int i = 0; i < TAM; ++i)
                {
                    dibujarDado(dados[i]);      // Con esta función muestro los dados dibujados. Esta parte fue dificil de modificar.
                }

            int reglas = calcularReglas(dados,TAM);
            cout << "PUNTAJE DEL LANZAMIENTO: " << reglas << " PUNTOS" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;

            if (lanzamiento == 1)
            {
                maxRonda = reglas;
            }
            else if(reglas > maxRonda)   // Lógica para detectar el puntaje máximo entre los 3 lanzamientos de cada ronda.
            {
                maxRonda = reglas;
            }

            if (maxRonda == 100)  // Si se consiguen cien puntos en la RONDA, lo que equivale a hacer una escalera, ganamos la partida en esta ronda.
            {
                system("clear");
                // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
                cout << "ESCALERA!" << endl;  // Si se detecta la escalera nos vamos a otra pantalla que muestra este cartel , el puntaje , jugador y otros datos.
                mostrarVector(dados,TAM);
                  for (int i = 0; i < TAM; ++i)
                {
                    dibujarDado(dados[i]);      // Con esta función muestro los dados dibujados.
                }

                cout << "Cantidad de rondas que tardó en terminar la partida: " << rondas << endl;
                cout << "JUGADOR: " << nombre << endl;
                cout << "PUNTAJE: " << maxRonda << endl;
                cout << "HAS GANADO LA PARTIDA"<< endl;
                cin.ignore();
                cin.get();     // Esperar a que el usuario presione Enter
                // system("pause"); // para windows.

                break;  // No demasiado seguro de esto, este break está puesto acá como un intento de finalizar el juego apenas detecta una escalera.
            }

            if(reglas == 0)
            {
                puntajeTotal = 0;    // Resetear el valor del puntaje Total si obtenemos un sexteto--(6 dados numero 6)
            }

            if (lanzamiento <= lanzamientos)
            {
                cout << "Preparándose para el siguiente lanzamiento..." << endl; // Cartel para dar paso al siguiente lanzamiento.
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
            }

        }
        puntajeTotal += maxRonda;  // Actualizar el puntaje total.
        if (puntajeTotal >= 100)  // SI el puntaje es mayor o igual a cien, llegamos al final del juego.
        {
            system("clear");
            // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
            cout << "-------------------------------------------------------------------" << endl;
            cout << "HAS TERMINADO LA PARTIDA"<< endl;
            cout << "JUGADOR: "<<nombre<< endl;
            cout << "PUNTAJE: "<<puntajeTotal<<endl;
            cout << "Cantidad de rondas que tardó en terminar la partida: "<< rondas<< endl;
            cout << "-------------------------------------------------------------------" << endl;
            // system("pause"); // para windows.
            break;
        }
        else
        {
            system("clear");
            // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
            cout << "-------------------------------------------------------------------" << endl;
            cout << "RONDA N °" << rondas << endl;
            cout << "JUGADOR: " << nombre << endl;
            cout << "PUNTAJE: " << puntajeTotal << endl;
            cout << "-------------------------------------------------------------------" << endl;
            cin.ignore();

            // system("pause"); // para windows.
        }
    }
} // fin del modo 1 jugador.*/

#endif // MODOUNJUGADOR_H_INCLUDED

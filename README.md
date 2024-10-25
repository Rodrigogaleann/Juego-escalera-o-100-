
![Leonardo_Phoenix_Six_weathered_dice_scattered_haphazardly_acro_3](https://github.com/user-attachments/assets/71ab9d4c-be44-47fc-9ec6-c2ffa4847fee)

Entrega proyecto final de faculta UTN de la materia programacion

# ESCALERA O CIEN

Adjunto proyecto final de la materia programación. 

El proyecto consistia en crear un juego de mesa que tenga version para una persona y su vez manual para probar todas las convinaciones de dados.

El juego consiste en arrojar 6 dados en 3 manos el mejor puntaje de la tirada se suma al puntaje total, el que sumar mayor puntaje obtenga y llegue a 100 primero gana el juego, pero hay cierta convinaciones de dados que pueden resetear el puntaje a 0 (cero), asi tambien pueden ayudarte y sumar 100 puntos en un solo tiro. 
Despues de cada ronda se mostrara el mejor puntaje que se obtuvo y el nombre del jugador, al finalizar mostrar un cartel de CONGRATULATIONS !! para el ganador del juego.

## Reglas del juego 

***SEXTETO DE 6*** : Mala suerte !! , si en alguna tirada de la ronda slio en los 6 dados el numero 6 el puntaje se reiniciara a 0.

***SEXTETO DE OTRO NUMERO***:Enhorabuena, si obtuviste en los 6 dados el mismo lado ese numer se multiplica por 10 y se sumara en tu puntaje total.

***ESCALERA***: Felicitaciones !! ganaste el juego, en este caso al sacar en los 6 dados numeros distintos automaticamente sumas 100 punto por lo que se da ganada la partida.


# CODIGO

## Main

En este archivo tipo C++ encontramos trasfondo del menú con todas las opciones disponible del juego, con funciones pasadas por parámetro y por referencias.
Algunas funciones son de tipo VOID y otras de tipo ENTERAS.

```C++
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
```
## Interfaz_Menu

En este archivo tipo .h vemos la interfaz grafica del menú donde encontraremos todos los modos de juegos, mostrar reglamento y mejor puntuación. Es una función que esta declara ni bien se compila el código para que el usuario pueda elegir la opción deseada.

```C++
#ifndef HEADERUNO_H_INCLUDED
#define HEADERUNO_H_INCLUDED

void mostrarMenu();

void mostrarMenu()  // FUNCIÓN Para mostrar menú.
{
        system("clear"); // Para limpiar consola en Linux. Comentar esta línea y usar la de abajo si se es usuario de Windows.
        // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.

        cout << "|------------ESCALERA O CIEN---------------|" << endl;
        cout << "|------------MENU PRINCIPAL----------------|" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|1 - Iniciar juego nuevo para un jugador   |" << endl;
        cout << "|2 - Iniciar juego nuevo para dos jugadores|" << endl;
        cout << "|3 - Mostrar puntuacion mas alta           |" << endl;
        cout << "|4 - Cargar dados manualmente              |" << endl;
        cout << "|5 - Mostrar Reglamento                    |" << endl;
        cout << "|0 - Salir del juego                       |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "Ingresa la opcion elegida: ";
} // Fin de la función mostrar menu
```

## Mostrar_Reglamento

En este archivo tipo .h podemos ver que es una función de tipo VOID que se muestra solo si el usuario presiona la opción 5, se mostrara el reglamento del juego.

```C++
#ifndef MOSTRARREGLAMENTO_H_INCLUDED
#define MOSTRARREGLAMENTO_H_INCLUDED

void mostrarReglamento()  // Función extra para mostrar el reglamento del juego.
{
    system ("clear");  // Limpiar la consola en linux.
    // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
    cout << "|El objetivo del juego es llegar a los 100 puntos o hacer una escalera." << endl;
    cout << "|Cada ronda se compone de 3 lanzamientos, el puntaje maximo de la ronda es el puntaje mayor de esos 3 lanzamientos, NO la suma de los mismos." << endl;
    cout << "|Una escalera se compone de un lanzamiento en el que todos los números de los 6 dados sean distintos entre sí." << endl;
    cout << "|Si todos los dados lanzados son iguales, a excepción del seis, se considera un sexteto, y el puntaje del dado repetido se multiplicara por 10." << endl;
    cout <<"|Si conseguimos un Sexteto de 6 dados con valor 6 tendremos un sexteto negativo, no se obtiene puntaje en el lanzamiento y el puntaje total se resetea a 0."<<endl;
    cout <<"|En el modo de dos jugadores, el primero en llegar a los 100 puntos o hacer una escalera será el ganador de la partida." << endl;
}  // Fin de la función mostrar reglamento.

#endif // MOSTRARREGLAMENTO_H_INCLUDED

#endif // HEADERUNO_H_INCLUDED
```

# Modo_un_jugador

En este archivo tipo .h podemos ver que es una función de tipo VOID en la misma se desarrollo del modo un jugador, cuentas con la interfaz gráfica donde muestra el NUMERO DE RONDA, NOMBRE DEL JUGADOR y PUNTAJE OBTENIDO, cuando el usuario llegue a 100 puntos ganara. Esta función es llamada cuando el usuario aprete la opción de MODO UN JUGADOR.

```C++
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
```

## Modo_dos_jugadores

En este archivo tipo .h podemos ver que es una función de tipo VOID en la misma se desarrollo del modo de 2 jugador, cuentas con la interfaz gráfica de los 2 participantes  donde muestra el NUMERO DE RONDA, NOMBRE DEL JUGADOR , PUNTAJE OBTENIDO EN CADA RONDA y AL GANADOR DEL JUEGO, cuando uno de los usuarios llegue a 100 puntos ganara. Esta función es llamada cuando el usuario aprete la opción de MODO DOS JUGADOR.

```C++
#ifndef MODODOSJUGADORES_H_INCLUDED
#define MODODOSJUGADORES_H_INCLUDED



void modoDosJugadores(int* puntuacionAlta, string* nombrePuntuacionAlta);

void modoDosJugadores(int* puntuacionAlta, string* nombrePuntuacionAlta) // COMIENZO DE LA FUNCIÓN DEL MODO DOS JUGADORES.
{
    system("clear");
    // system ("cls"); // limpiar la consola en windows.
    const int TAM = 6;
    int dados[TAM] = {1,2,3,4,5,6};
    int lanzamientos = 3; // numero de lanzamientos.
    int puntajeTotalUno = 0;// acumulador de puntaje.
    int puntajeTotalDos = 0; // acumulador de puntaje 2
    int puntajeMaximo = 100; // puntaje máximo.

    int rondasUno = 0; // contador de rondas.
    int rondasDos = 0; // contador de rondas 2.
    string nombreUno; // string para ingresar nombre del primer jugador.
    string nombreDos; // string para ingresar el nombre del segundo jugador.

    cout << "Ingrese el nombre del jugador Uno: " << endl;
    cin.ignore();  // ingreso de nombre.
    getline(cin, nombreUno); // ingreso de nombre.

    cout << "Ingrese el nombre del jugador Dos: " << endl;
    cin.ignore(); // ingreso del segundo nombre.
    getline(cin,nombreDos); // ingreso del segundo nombre.

    while(puntajeMaximo <=100)
    {
        rondasUno++; // contador para las rondas del primer jugador.
        rondasDos++;// contador de rondas para el segundo jugador.

        int maxRondaUno = 0; // variable para guardar la ronda máxima del jugador uno.
        int maxRondaDos = 0; // variable para guardar la ronda máxima del jugador dos.

        for(int lanzamiento = 1; lanzamiento <= lanzamientos; lanzamiento++) // For rondas para el primer jugador.
        {
            system ("clear"); // Limpiar consola en linux.
            //system ("cls"); // Limpiar consola en windows.

            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "TURNO DE: " << nombreUno << " | " << "RONDA N° " << rondasUno << " | " << "PUNTAJE TOTAL: " << puntajeTotalUno << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxRondaUno << endl;
            cout << "LANZAMIENTO NÚMERO: " << lanzamiento << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cargarVectorAleatorio(dados, TAM);
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "EL RESULTADO DE LOS DADOS ES: " << endl;
            mostrarVector(dados,TAM);

            for(int i = 0; i <TAM; i++) // for para recorrer los elementos del vector.
            {
                dibujarDado(dados[i]); // Mostrar dados dibujados.
            }

            int reglas = calcularReglas(dados,TAM);
            cout << "PUNTAJE DEL LANZAMIENTO: " << reglas << " PUNTOS" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;

            if (lanzamiento == 1)
            {
                maxRondaUno = reglas;
            }
            else if(reglas > maxRondaUno)   // Lógica para detectar el puntaje máximo entre los 3 lanzamientos de cada ronda.
            {
                maxRondaUno = reglas;
            }

            if (maxRondaUno == 100)  // Si se consiguen mil puntos en la RONDA, lo que equivale a hacer una escalera, ganamos la partida en esta ronda.
            {
                system("clear");
                // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
                cout << "ESCALERA!" << endl;  // Si se detecta la escalera nos vamos a otra pantalla que muestra este cartel , el puntaje , jugador y otros datos.
                mostrarVector(dados,TAM);
                for (int i = 0; i < TAM; ++i)
                {
                    dibujarDado(dados[i]);      // Con esta función muestro los dados dibujados.
                }

                cout << "Cantidad de rondas que tardó en terminar la partida: " << rondasUno << endl;
                cout << "JUGADOR: " << nombreUno << endl;
                cout << "PUNTAJE: " << maxRondaUno << endl;
                cout << "HAS GANADO LA PARTIDA"<< endl;
                cin.ignore();
                cin.get();     // Esperar a que el usuario presione Enter
                // system("pause"); // para windows.

                break;  // No demasiado seguro de esto, este break está puesto acá como un intento de finalizar el juego apenas detecta una escalera.
            }

            if(reglas == 0)
            {
                puntajeTotalUno = 0;    // Resetear el valor del puntaje Total si obtenemos un sexteto--(6 dados numero 6)
            }

            if (lanzamiento <= lanzamientos)
            {
                cout << "Preparándose para el siguiente lanzamiento..." << endl; // Cartel para dar paso al siguiente lanzamiento.
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
            }

        } // Fin del for para el Jugador Uno.

        puntajeTotalUno+=maxRondaUno; // Actualizar los puntajes para el jugador uno.

        system("clear");
        // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
        cout << "-------------------------------------------------------------------" << endl;
        cout << "RONDA N °" << rondasUno << endl;
        cout <<"PROXIMO TURNO:" << nombreDos << endl;
        cout << "PUNTAJE "<< nombreUno <<" : "<< puntajeTotalUno << endl;
        cout <<"PUNTAJE "   <<nombreDos <<": " << puntajeTotalDos << endl;
        cout << "Presione Enter para continuar..." << endl; //// FORMA PARA REEMPLAZAR A SYSTEM ("PAUSE") DE WINDOWS EN LINUX.
        cout << "-------------------------------------------------------------------" << endl;
        cin.ignore();  // Ignorar el carácter de nueva línea restante
        cin.get();     // Esperar a que el usuario presione Enter
        // system("pause"); // para windows.

        for(int lanzamiento = 1; lanzamiento <= lanzamientos; lanzamiento++) // For rondas para el segundo jugador.
        {
            system ("clear"); // Limpiar consola en linux.
            //system ("cls"); // Limpiar consola en windows.

            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "TURNO DE: " << nombreDos << " | " << "RONDA N° " << rondasDos << " | " << "PUNTAJE TOTAL: " << puntajeTotalDos << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxRondaDos << endl;
            cout << "LANZAMIENTO NÚMERO: " << lanzamiento << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cargarVectorAleatorio(dados, TAM);
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "EL RESULTADO DE LOS DADOS ES: " << endl;
            mostrarVector(dados,TAM);

            for(int i = 0; i <TAM; i++) // for para recorrer los elementos del vector.
            {
                dibujarDado(dados[i]); // Mostrar dados dibujados.
            }

            int reglas = calcularReglas(dados,TAM);
            cout << "PUNTAJE DEL LANZAMIENTO: " << reglas << " PUNTOS" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;

            if (lanzamiento == 1)
            {
                maxRondaDos = reglas;
            }
            else if(reglas > maxRondaDos)   // Lógica para detectar el puntaje máximo entre los 3 lanzamientos de cada ronda.
            {
                maxRondaDos = reglas;
            }

            if (maxRondaDos == 100)  // Si se consiguen mil puntos en la RONDA, lo que equivale a hacer una escalera, ganamos la partida en esta ronda.
            {
                system("clear");
                // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
                cout << "ESCALERA!" << endl;  // Si se detecta la escalera nos vamos a otra pantalla que muestra este cartel , el puntaje , jugador y otros datos.
                mostrarVector(dados,TAM);
                for (int i = 0; i < TAM; ++i)
                {
                    dibujarDado(dados[i]);      // Con esta función muestro los dados dibujados.
                }

                cout << "Cantidad de rondas que tardó en terminar la partida: " << rondasDos << endl;
                cout << "JUGADOR: " << nombreDos << endl;
                cout << "PUNTAJE: " << maxRondaDos << endl;
                cout << "HAS GANADO LA PARTIDA"<< endl;
                cin.ignore();
                cin.get();     // Esperar a que el usuario presione Enter
                // system("pause"); // para windows.

                break;  // No demasiado seguro de esto, este break está puesto acá como un intento de finalizar el juego apenas detecta una escalera.
            }

            if(reglas == 0)
            {
                puntajeTotalDos = 0;    // Resetear el valor del puntaje Total si obtenemos un sexteto--(6 dados numero 6)
            }

            if (lanzamiento <= lanzamientos)
            {
                cout << "Preparándose para el siguiente lanzamiento..." << endl; // Cartel para dar paso al siguiente lanzamiento.
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
            }

        } // Fin del for para el Jugador Dos.

        puntajeTotalDos+=maxRondaDos; // Acumulador de puntaje para El jugador Dos.

        system("clear");
        // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
        cout << "-------------------------------------------------------------------" << endl;
        cout << "RONDA N °" << rondasDos << endl;
        cout <<"PROXIMO TURNO:" << nombreUno << endl;
        cout << "PUNTAJE "<< nombreDos <<" : "<< puntajeTotalDos << endl;
        cout <<"PUNTAJE "   <<nombreUno <<": " << puntajeTotalUno << endl;
        cout << "Presione Enter para continuar..." << endl; //// FORMA PARA REEMPLAZAR A SYSTEM ("PAUSE") DE WINDOWS EN LINUX.
        cout << "-------------------------------------------------------------------" << endl;
        cin.ignore();  // Ignorar el carácter de nueva línea restante
        cin.get();     // Esperar a que el usuario presione Enter
        // system("pause"); // para windows.

        if(puntajeTotalUno >= puntajeMaximo)
        {
            system("clear");
            cout << "-------------------------------------------------------------------" << endl;
            cout << "EL GANADOR ES: " << nombreUno << endl;        // El primero que llega a 100 puntos gana la partida.
            cout << "Ha ganado: " << puntajeTotalUno << " puntos. " <<endl;
            cout << "-------------------------------------------------------------------" << endl;
        cin.ignore();  // Ignorar el carácter de nueva línea restante
        cin.get();     // Esperar a que el usuario presione Enter
        // system("pause"); // para windows.
            break;
        }
        else if(puntajeTotalDos >= puntajeMaximo)
        {
            system ("clear");
            cout << "-------------------------------------------------------------------" << endl;
            cout << "EL GANADOR ES: " << nombreDos << endl;
            cout << "Ha ganado: " << puntajeTotalDos << " puntos . " <<endl;
            cout << "-------------------------------------------------------------------" << endl;
        cin.ignore();  // Ignorar el carácter de nueva línea restante
        cin.get();     // Esperar a que el usuario presione Enter
        // system("pause"); // para windows.
            break;
        }

    }  // Fin del While.
     if (puntajeTotalUno > *puntuacionAlta)
    {
        *puntuacionAlta = puntajeTotalUno;
        *nombrePuntuacionAlta = nombreUno;
    }
    else if(puntajeTotalDos > *puntuacionAlta)
    {
        *puntuacionAlta = puntajeTotalDos;
        *nombrePuntuacionAlta = nombreDos;
    }
```
## Modo_Manual

En este archivo tipo .h podemos ver que es una función de tipo VOID en la misma se desarrollo del modo manual, cuentas con la interfaz gráfica del modo de un jugador donde muestra el NUMERO DE RONDA, NOMBRE DEL JUGADOR y PUNTAJE OBTENIDO EN CADA RONDA este modo se desarrollo para que los profesores prueben toda las combinaciones de dados posibles sin necesidad de hacer los lanzamientos. Esta función es llamada cuando el usuario aprete la opción de MODO MANUAL .

```C++
#ifndef MODOMANUAL_H_INCLUDED
#define MODOMANUAL_H_INCLUDED

#include "calcularReglas.h"
#include "headerUno.h"

void modoManual();

void modoManual()
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
            cargarVectorManual(dados, TAM);
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "EL RESULTADO DE LOS DADOS ES: " << endl;
            mostrarVector(dados,TAM);
              for (int i = 0; i < TAM; i++)
                {
                    dibujarDado(dados[i]);      // Con esta función muestro los dados dibujados.
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

            if (maxRonda == 100)  // Si se consiguen mil puntos en la RONDA, lo que equivale a hacer una escalera, ganamos la partida en esta ronda.
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
                cout << "Presiona Enter para continuar..." << endl;
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
} // fin del modo manual.

#endif // MODOMANUAL_H_INCLUDED

} // FIN DE LA FUNCIÓN DEL MODO DOS JUGADORES.


#endif // MODODOSJUGADORES_H_INCLUDED
```

## Calcular_Reglas

En este archivo tipo .h podemos ver funciones de VOID y ENTERAS en la misma se desarrollo la esencia del juego es una función donde se va analizar cada lanzamiento del jugador para contemplar las reglas del juego con todas las combinaciones de dados posible. Esta función es llamada en cada lanzamiento de cada jugador. También tiene incluida la función de Dibujar dados para que muestre en forma grafica el lanzamiento de cada jugador.

```C++
#ifndef CALCULARREGLAS_H_INCLUDED
#define CALCULARREGLAS_H_INCLUDED

void cargarVectorManual(int vec[], int tam); // Función para cargar vector.
void mostrarVector(int vec[], int tam); // Función para mostrar vector.
void cargarVectorAleatorio (int vec[], int tam); // Función para cargar vector aleatorio.
int calcularReglas(int vec[], int tam); // Función para calcular las reglas.
void dibujarDado(int valor); // Función para dibujar dados.

void dibujarDado(int valor)  // Función para dibujar los dados.
{
    switch(valor) // switch para asignar un dibujo de dados a cada elemento del vector.
    {
    case 1:
        cout << "-----" << endl;
        cout << "|   |" << endl;
        cout << "| o |" << endl;
        cout << "|   |" << endl;
        cout << "-----" << endl;
        break;
    case 2:
        cout << "-----" << endl;
        cout << "|o  |" << endl;
        cout << "|   |" << endl;
        cout << "|  o|" << endl;
        cout << "-----" << endl;
        break;
    case 3:
        cout << "-----" << endl;
        cout << "|o  |" << endl;
        cout << "| o |" << endl;
        cout << "|  o|" << endl;
        cout << "-----" << endl;
        break;
    case 4:
        cout << "-----" << endl;
        cout << "|o o|" << endl;
        cout << "|   |" << endl;
        cout << "|o o|" << endl;
        cout << "-----" << endl;
        break;
    case 5:
        cout << "-----" << endl;
        cout << "|o o|" << endl;
        cout << "| o |" << endl;
        cout << "|o o|" << endl;
        cout << "-----" << endl;
        break;
    case 6:
        cout << "-----" << endl;
        cout << "|o o|" << endl;
        cout << "|o o|" << endl;
        cout << "|o o|" << endl;
        cout << "-----" << endl;
        break;
    default:
        cout << "dado no válido" << endl;
        break;
    }
} // Fin de la función para mostrar dados dibujados.


void cargarVectorManual(int vec[],int tam) // función para cargar un vector manualmente, será usada para cargar los dados del vector.
{
    int i;
    for (i=0; i < tam; i++)
    {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correctamente cargado..."<<endl;
}  // Fin de cargar vector manual.*/

void mostrarVector (int vec[], int tam) // Función para mostrar los elementos del vector.
{
    for(int i = 0; i < tam; i++)
    {
        cout << " Dado " << i+1 << " : " << vec[i] << endl;  // Mostrar vector con un for.
    }
} // Fin de mostrar vector.

void cargarVectorAleatorio (int vec[], int tam) // Función para cargar vector aleatorio.
{
    for(int i = 0; i <= tam; i++)
    {
        vec[i] = (rand()% 6 + 1);  // Esta línea de código permite asignar números aleatorios(hasta 6) a cada elemento del vector.
    }
} // fin de cargar vector aleatorio.

int calcularReglas(int vec[], int tam) // Comienzo de la función para calcular reglas.
{
    bool todosIguales = true;       // Bandera para detectar si todos los elementos de mi vector son iguales.
    int primerElemento = vec[0];    // Definir que el primer elemento del vector es el vector en posición cero. // (Esto es para buscar los sextetos)

    for (int i = 0; i < tam; i++) // Recorrer el vector en tdos sus elementos.
    {
        if (vec[i] != primerElemento)  //SI el valor de cualquier elemento no es igual a mi primer elemento, ya no se cumple mi bandera.
        {
            todosIguales = false;  // con está lógica tengo definido si todos los elementos del vector van a ser iguales o no.
            break;
        }
    }

    // A)Encontrar los sextetos:

    if (todosIguales && primerElemento != 6)   // Si todos los dados son iguales Y el dado NO es igual a SEIS:
    {
        cout << "SEXTETO" << endl;
        return primerElemento * 10;         // MULTIPLICO EL VALOR DEL DADO X 10. PRIMERA JUGADA DEL JUEGO. SEXTETO.
    }
    else if(todosIguales && primerElemento == 6)   // Si todos los dados son iguales pero el dado es SEIS:
    {
        cout << "SEXTETO6 -- " << endl;
        cout << "Se resetea el puntaje total a 0 " << endl;
        return primerElemento * 0;          // MULTIPLICO EL VALOR DEL DADO X 0. SEGUNDA (JUGADA?) DEL JUEGO. SEXTETO--, RESETEA EL PUNTAJE TOTAL A 0.
    }

    // B)Encontrar la escalera:

    else
    {
        int frecuencia[tam] = {0}; // Creaar un vector de frecuencias para contar la cantidad de veces que aparece cada número.

        for (int i = 0; i < tam; i++)
        {
            if (vec[i] >= 1 && vec[i] <= tam)
            {
                frecuencia[vec[i] - 1]++; // Contar la frecuencia de cada número en el vector.
            }
        }

        bool escalera = true;  // Bandera para detectar la escalera.
        for (int i = 0; i < tam; i++)
        {
            if (frecuencia[i] != 1)      // Verificar si cada número del 1 al 6 aparece una vez.
            {
                escalera = false; // Si algún número no aparece una vez, NO es una escalera.
                break;  // CIERTAS dudas sobre si el uso de este break está bien o si está de mas.
            }
        }

        if (escalera)  // // Si encontramos una escalera, el jugador gana la partida.
        {

            return 100; // Puntaje alto para indicar que el jugador ha ganado.
        }

        //C) Sumar los dados cuando no se produce ninguna jugada especial:

        else
        {
            int suma = 0;
            for (int i = 0; i < tam; i++)
            {
                suma += vec[i]; // Suma de dados "normal".
            }
            return suma;
        }
    }
}   // Fin de la función para definir las jugadas.

#endif // CALCULARREGLAS_H_INCLUDED

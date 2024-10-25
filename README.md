
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


## CODIGO


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

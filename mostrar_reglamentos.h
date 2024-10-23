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
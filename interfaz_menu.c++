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


#endif // HEADERUNO_H_INCLUDED
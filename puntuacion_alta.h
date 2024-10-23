#ifndef MOSTRARPUNTACIONALTA_H_INCLUDED
#define MOSTRARPUNTACIONALTA_H_INCLUDED

void mostrarPuntuacionAlta(int puntuacionAlta, const string& nombrePuntuacionAlta);

void mostrarPuntuacionAlta(int puntuacionAlta, const string& nombrePuntuacionAlta)  // Función para mostrar la puntuación más alta.
{
    system ("clear");
    // system("cls"); // Quitar comentario de esta línea para limpiar consola en Windows.
    cout << "-------------------------------------------------------------------" << endl;

    cout << "El jugador con mayor puntuación es: " << nombrePuntuacionAlta << endl;
    cout << "Su puntuación es: "<< puntuacionAlta << endl;
    cout << "Presiona Enter para volver al menú principal" << endl;

    cout << "-------------------------------------------------------------------" << endl;

    cin.ignore();  // Ignorar el carácter de nueva línea restante  // COMENTAR ESTA LINEA
    cin.get();     // Esperar a que el usuario presione Enter  // COMENTAR ESTA LINEA
    //system ("pause"); // DESCOMENTAR ESTA LINEA PARA WINDOWS.

} // Fin de la función para mostrar la puntuación más alta.

#endif // MOSTRARPUNTACIONALTA_H_INCLUDED
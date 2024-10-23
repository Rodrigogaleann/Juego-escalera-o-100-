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


} // FIN DE LA FUNCIÓN DEL MODO DOS JUGADORES.


#endif // MODODOSJUGADORES_H_INCLUDED

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
#include "validarNotas.h"
#include <iostream>
#include <limits>

using namespace std;

// CRUCIAL: Definir explícitamente el constructor de la clase
LectorDatos::LectorDatos() {}

int LectorDatos::validarEntero(const string &mensaje)
{
    int valor;
    while (true)
    {
        cout << mensaje;
        if (cin >> valor)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "-> [ERROR] Ingreso invalido. Debe ser un numero entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float LectorDatos::validarNota(const string &mensaje)
{
    float nota;
    while (true)
    {
        cout << mensaje;
        if (cin >> nota)
        {
            if (nota >= 0.0f && nota <= 10.0f)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return nota;
            }
            cout << "-> [ERROR] La nota debe estar estrictamente en el rango de 0.00 a 10.00.\n";
        }
        else
        {
            cout << "-> [ERROR] Ingreso invalido. Debe ser un numero decimal o entero.\n";
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
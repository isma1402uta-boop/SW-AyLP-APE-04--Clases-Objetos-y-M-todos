#include "validarNotas.h"
#include <iostream>
#include <limits> 

using namespace std;

//Metodo para validar un numero dentro del sistema, se asegura de que el usuario ingrese un numero entero valido
int LectorDatos::validarEntero(const string& mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        
        if (cin >> numero) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return numero; 
        } else {
            cout << "Entrada inválida. Por favor, ingrese un número entero." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

// Método para validar una nota de tipo flotante entre 0 y 10 para segurarnos el rango exacto propuesto
float LectorDatos::validarNota(const string& mensaje) {
    float nota;
    while (true) {
        cout << mensaje;
        
        if (cin >> nota) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el salto de línea
            
            // Verificación del rango requerido en la guía (0 a 10)
            if (nota >= 0.0f && nota <= 10.0f) {
                return nota; // Retorna solo si está en el rango correcto
            } else {
                cout << "-> Entrada inválida. La nota debe estar entre 0.00 y 10.00." << endl;
            }
        } else {
            cout << "-> Entrada inválida. Por favor, ingrese un número decimal válido." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}
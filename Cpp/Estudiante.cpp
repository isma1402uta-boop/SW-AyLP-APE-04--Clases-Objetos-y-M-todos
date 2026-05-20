#include "Estudiantes.h"
#include <iostream>
#include <iomanip> // Para dar formato de decimales (0.00) en la consola

using namespace std;


// CONSTRUCTORES

// Constructor por defecto
Estudiantes::Estudiantes() {
    cedula = "";
    nombre = "";
    apellido = "";
    nota1 = 0.0f;
    nota2 = 0.0f;
    nota3 = 0.0f;
    promedio = 0.0f;
}

// Constructor parametrizado
Estudiantes::Estudiantes(string _cedula, string _nombre, string _apellido, float _n1, float _n2, float _n3) {
    cedula = _cedula;
    nombre = _nombre;
    apellido = _apellido;
    nota1 = _n1;
    nota2 = _n2;
    nota3 = _n3;
    calcularPromedio(); // Calcula el promedio automáticamente al crear el objeto
}


// IMPLEMENTACIÓN DE MÉTODOS GET Y SET

void Estudiantes::setCedula(string _cedula) { cedula = _cedula; }
string Estudiantes::getCedula() const { return cedula; }

void Estudiantes::setNombre(string _nombre) { nombre = _nombre; }
string Estudiantes::getNombre() const { return nombre; }

void Estudiantes::setApellido(string _apellido) { apellido = _apellido; }
string Estudiantes::getApellido() const { return apellido; }

void Estudiantes::setNota1(float _n1) { nota1 = _n1; calcularPromedio(); }
float Estudiantes::getNota1() const { return nota1; }

void Estudiantes::setNota2(float _n2) { nota2 = _n2; calcularPromedio(); }
float Estudiantes::getNota2() const { return nota2; }

void Estudiantes::setNota3(float _n3) { nota3 = _n3; calcularPromedio(); }
float Estudiantes::getNota3() const { return nota3; }

float Estudiantes::getPromedio() const { return promedio; }


// MÉTODOS DE LÓGICA Y REPORTES

// Método para calcular el promedio
void Estudiantes::calcularPromedio() {
    promedio = (nota1 + nota2 + nota3) / 3.0f;
}

// Método para determinar si aprueba o reprueba (Mínimo 7.00 para aprobar)
bool Estudiantes::determinarAprobacion() const {
    return (promedio >= 7.0f);
}

// Método para mostrar la información detallada del estudiante
void Estudiantes::mostrarInformacion() const {
    cout << "---------------------------------------------\n";
    // Tildes omitidas en el texto para asegurar compatibilidad en la terminal de Windows
    cout << "Cedula:   " << cedula << "\n";
    cout << "Alumno:   " << apellido << " " << nombre << "\n";
    
    // Forzamos a mostrar siempre 2 decimales para las notas
    cout << fixed << setprecision(2); 
    cout << "Nota 1:   " << nota1 << "  |  Nota 2: " << nota2 << "  |  Nota 3: " << nota3 << "\n";
    cout << "Promedio: " << promedio << "\n";
    
    // Evaluamos el método de aprobación para el mensaje final
    if (determinarAprobacion()) {
        cout << "Estado:   [APROBADO]\n";
    } else {
        cout << "Estado:   [REPROBADO]\n";
    }
    cout << "---------------------------------------------\n";
}